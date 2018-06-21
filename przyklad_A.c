#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {

  int fd;
  int n_read, m_written;
  char buf[10]; // bufor 10 znakow
  
  /* otworz plik a.txt do zapisu */
  
  fd = open("a.txt", OWRONLY | O_APPEND);
  
  /* sprawdz czy otwarcie odbylo sie poprawnie */
  
  if (fd == -1) { /* blad podczas otwarcia komunikat oraz wyjscie z programu */
    perror("Error in 'open'");
    exit(1);
  }
  
  printf("Wpisz tekst i naciśnij Enter (lub naciśnij Ctrl+D)\n");
  
  n_read = read(0, buf, sizeof(buf)); // czytaj ze stantadowego we 0
  
  if(n_read == -1) {
    perror("Blad w 'read'\n");
    
  //close(fd);                      // zamknij deskryptor pliku
  
  m_written = write(fd, buf, n_read);  //write do pliku
  
  if(m_written == -1) {
    perror("Blad w 'write'\n");
    exit(1);
  }
  
  close(fd);                        // zamkniecie deskryptora pliku
  
  printf("Odczytano: %d bajtow, zapisano: %d bajtow, tekst: %s\n", n_read, m_written, buf);
  printf("Sprawdz zawartosc pliku a.txt!\n");
  
  exit(0);
}
