#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include "include/cJSON.h"
#include "http.h"

void string_buffer_initialize(string_buffer_t *sb)
{
    sb->len = 0;
    sb->ptr = malloc(sb->len + 1);
    sb->ptr[0] = '\0';
}

void string_buffer_finish(string_buffer_t *sb)
{
    free(sb->ptr);
    sb->len = 0;
    sb->ptr = NULL;
}

size_t string_buffer_callback(void *buf, size_t size, size_t nmemb, void *data)
{
    string_buffer_t *sb = data;
    size_t new_len = sb->len + size * nmemb;
    sb->ptr = realloc(sb->ptr, new_len + 1);
    memcpy(sb->ptr + sb->len, buf, size * nmemb);
    sb->ptr[new_len] = '\0';
    sb->len = new_len;
    return size * nmemb;
}

size_t write_callback(void *buf, size_t size, size_t nmemb, void *data)
{
    return string_buffer_callback(buf, size, nmemb, data);
}

http_return http(char *mymethod, char *myurl, char *mydata)
{
    
    CURL *curl;
    CURLcode res;
    string_buffer_t strbuf;
    http_return HTTP_RESULT = {
        .update_id = 0,
        .text = ""};

    string_buffer_initialize(&strbuf);
    /* init the curl session */
    curl = curl_easy_init();
    if (!curl)
    {
        fprintf(stderr, "Fatal: curl_easy_init() error.\n");
        string_buffer_finish(&strbuf);
        return HTTP_RESULT;
    }
    /* specify URL to get OR POST */
    curl_easy_setopt(curl, CURLOPT_URL, myurl);
    if (strcmp(mymethod, "POST") == 0)
    {
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, mydata);
    }
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* send all data to this function */
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    /* we pass our 'strbuf' struct to the callback function */
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &strbuf);

    /* get it! */
    res = curl_easy_perform(curl);
    /* check for errors */
    if (res != CURLE_OK)
    {
        fprintf(stderr, "Request failed: curl_easy_perform(): %s\n", curl_easy_strerror(res));

        curl_easy_cleanup(curl);
        string_buffer_finish(&strbuf);
        return HTTP_RESULT;
    }
    /*
     * Now, our strbuf.ptr points to a memory block that is strbuf.len
     * bytes big and contains the remote resource.
     *
     * Do something nice with it!
     */
    //  printf( "%s\n\n", strbuf.ptr );
    //  printf("%lu bytes retrieved\n", (unsigned long)strbuf.len);

    
    const char *json_response = strbuf.ptr;

    // Analizar la respuesta JSON
    cJSON *root = cJSON_Parse(json_response);
    if (root == NULL)
    {
        printf("Error al analizar JSON.\n");
        return HTTP_RESULT;
    }

    // Obtener el arreglo de resultados
    cJSON *result = cJSON_GetObjectItem(root, "result");
    if (result != NULL && result->type == cJSON_Array)
    {
        int num_results = cJSON_GetArraySize(result);
        cJSON *update = cJSON_GetArrayItem(result, num_results - 1);
        if (update != NULL && update->type == cJSON_Object)
        {
            cJSON *update_id = cJSON_GetObjectItem(update, "update_id");
            if (update_id != NULL && update_id->type == cJSON_Number)
            {
                int id = update_id->valueint;
                HTTP_RESULT.update_id = id;
            }

            cJSON *message = cJSON_GetObjectItem(update, "message");
            if (message != NULL && message->type == cJSON_Object)
            {

                cJSON *text = cJSON_GetObjectItem(message, "text");
                if (text != NULL && text->type == cJSON_String)
                {
                    char *m_text = strdup(text->valuestring);
                    HTTP_RESULT.text = m_text;
                }
            }
        }
    }

    // Liberar la memoria utilizada por cJSON
    cJSON_Delete(root);
    // printf("result.text: %s\n", HTTP_RESULT.text);

    /* cleanup curl stuff */
    curl_easy_cleanup(curl);
    string_buffer_finish(&strbuf);
    return HTTP_RESULT;
}

http_return readLastMessage(const char *botID, int offset)
{
        
    // Construir la URL completa utilizando el botID pasado como parámetro
    char url[200];
    snprintf(url, sizeof(url), "https://api.telegram.org/bot%s/getUpdates?offset=%d", botID, offset);

    // Realizar la solicitud HTTP utilizando la URL construida
    struct http_return result = http("GET", url, "");
    return result;
}

void sendMessage(const char *botID, char *chat_id, const char *message)
{
    // Obtener el tamaño requerido para la URL completa
    int url_size = snprintf(NULL, 0, "https://api.telegram.org/bot%s/sendMessage", botID);
    // Asignar memoria dinámica para la URL
    char *url = malloc(url_size + 1);
    snprintf(url, url_size + 1, "https://api.telegram.org/bot%s/sendMessage", botID);

    // Obtener el tamaño requerido para los datos
    int data_size = snprintf(NULL, 0, "chat_id=%s&text=%s", chat_id, message);
    // Asignar memoria dinámica para los datos
    char *data = malloc(data_size + 1);
    snprintf(data, data_size + 1, "chat_id=%s&text=%s", chat_id, message);

    // Realizar la solicitud HTTP utilizando la URL y los datos construidos
    struct http_return result = http("POST", url, data);

    // Liberar la memoria asignada
    free(url);
    free(data);
}
