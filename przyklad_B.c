#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> // lseek

int main()
{
  int fd;
  off_t size;
  
  int n_read, m_written;
  char buf[12] = "Ala ma kota!";
  
  fd = open("a.txt", O_RDWR);
  
  /* sprawdz czy otwarcie sie powiodlo */
  
  if(fd == -1) { /* blad otwierania: wyswietl informacje o bledzie i zakoncz program */
    perror("Blad w 'open'");
    exit(1);
  }
  
  size = lseek(fd, 5, SEEK_CUR);
  
  /* sprawdz czy otwarcie bylo poprawne */
  
  if(size == -1)
  {
    perror("Blad w "lseek'");
    exit(1);
  }
  
  m_written = write(fd, buf, sizeof(buf));   //zapisz do pliku
  
  if(m_written == -1) {
    perror("Blad w 'write'\n");
    exit(1);
  }
  
  close(fd);
  
  exit(0);
}
