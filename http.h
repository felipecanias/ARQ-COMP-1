#ifndef HTTP_H
#define HTTP_H

// #include <stdlib.h>
// #include <stdio.h>

typedef struct string_buffer_s {
    char *ptr;
    size_t len;
}string_buffer_t;

typedef struct http_return {
    int update_id;
    char *text;
} http_return ;

void string_buffer_initialize(string_buffer_t *sb);
void string_buffer_finish(string_buffer_t *sb);
size_t string_buffer_callback(void *buf, size_t size, size_t nmemb, void *data);
size_t write_callback(void *buf, size_t size, size_t nmemb, void *data);

http_return http(char *mymethod, char *myurl, char *mydata);
http_return readLastMessage(const char *botID, int offset);
void sendMessage(const char *botID, char *chat_id, const char *message);

#endif  // HTTP_H
