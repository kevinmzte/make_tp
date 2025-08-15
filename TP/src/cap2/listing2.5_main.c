#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declaraciones de las funciones del listing2.5 */
typedef int temp_file_handle;
temp_file_handle write_temp_file(char* buffer, size_t length);
char* read_temp_file(temp_file_handle temp_file, size_t* length);

int main() {
    const char* mensaje = "Hola, archivo temporal!";
    size_t len = strlen(mensaje);

    // Escribir en archivo temporal
    temp_file_handle temp = write_temp_file((char*)mensaje, len);

    // Leer desde el archivo temporal
    size_t read_len;
    char* buffer = read_temp_file(temp, &read_len);

    // Mostrar el contenido leído
    printf("Leído (%zu bytes): %.*s\n", read_len, (int)read_len, buffer);

    free(buffer); // liberar memoria dinámica
    return 0;
}
