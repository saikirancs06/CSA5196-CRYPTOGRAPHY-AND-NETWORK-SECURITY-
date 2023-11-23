#include <stdio.h>
#include <string.h>
void rowcolumn (char message [], char key []) 
{
int messagelen= strlen (message);
int keyLen = strlen (key);
int rows = (messagelen + keyLen - 1) / keyLen; 
char transpositiontable[rows][keyLen];
int i, j, k = 0;
for (i = 0; i < rows; i++) 
{
 for (j = 0; j < keyLen; j++)
{
 if (k < messagelen)
 transpositiontable[i][j] = message[k++];
 else
transpositiontable[i][j] = ' ';
}
}
for (i = 0; i < keyLen; i++) 
{
 int col = key[i] - '0' - 1;
 for (j = 0; j < rows; j++) 
{
 printf("%c", transpositiontable[j][col]);
 }
}
 printf("\n");
}
int main() {
 char message[100], key[100];
 printf("Enter the message to encrypt: ");
 fgets(message, sizeof(message), stdin);
 printf("Enter the key for columnar transposition: ");
 fgets(key, sizeof(key), stdin);
 message [strcspn(message, "\n")] = '\0';
 key [strcspn(key, "\n")] = '\0';
 printf("\nEncrypted message: ");
 rowcolumn(message, key);
 return 0;
}
