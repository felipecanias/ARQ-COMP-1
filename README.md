# Proyecto Arq de Compus
Año: 2023

Integrantes:
- Borgogno
- Cañas
- Cetti

## Aclaraciones

Comando para compilar con la librería ncurses y curl:
```bash
Instalar librerias:

$ sudo apt install libncurses5-dev
$ sudo apt install libcurl4-openssl-dev

Compilar: 
$ gcc main.c http.c include/cJSON.c -o output -lncurses -lcurl -lpthread
o directamente:
$ make

Ejecutar:
$ ./output
```  

Emular Raspberry
```bash
qemu-system-arm   -M versatilepb   -cpu arm1176   -m 256   -hda 2023-05-03-raspios-bullseye-armhf.img -net nic  -net user   -dtb versatile-pb-buster.dtb   -kernel kernel-qemu-4.19.50-buster   -append 'root=/dev/sda2 panic=1'   -no-reboot -virtfs local,path=shared_files,security_model=none,mount_tag=host_share
``` 

montar carpeta compartida
```bash
sudo mount -t 9p -o trans=virtio host_share /ruta/guest
``` 

const char *BOT_TOKEN = "6156973481:AAHXgfu9nLrmqucDXTX3GXREczhjTqFVY64";
char *CHAT_ID = "6022803879";