#include <termios.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>
#include <time.h>

int main(){

   struct termios t;
   struct timespec t1, t2;
   t1.tv_sec = 0;
   t1.tv_nsec = 200000000L;
   speed_t s;
   int    actions, RTS_flag;

   int c = open("/dev/ttyS0",O_RDWR | O_NONBLOCK);
   printf("open : %d\n", c);

   tcflush(c, TCIFLUSH);

   bzero(&t, sizeof(t));
   printf("%d\n",tcgetattr(c, &t));

   s = B9600;
   cfsetospeed(&t, (speed_t)s);
   cfsetispeed(&t, (speed_t)s);



   /* enable the receiver and set local mode */
   t.c_cflag |= (CLOCAL | CREAD);

   /* set no parity, stop bits, data bits */
   t.c_cflag &= ~PARENB;
   t.c_cflag &= ~CSTOPB;

   /* set character size as 8 bits */
   t.c_cflag &= ~CSIZE;
   t.c_cflag |= CS8;

   t.c_cflag &= ~CRTSCTS;

   t.c_lflag &= ~(ICANON | ECHO | ISIG);
   t.c_oflag = ~OPOST;

   cfmakeraw(&t);

   actions = TCSANOW;
   t.c_cflag |= ((~TIOCM_DTR) | (~TIOCM_RTS));

   printf("%d\n", tcsetattr(c, actions, &t));

   tcgetattr(c, &t);

   actions = TCSANOW;
   t.c_cflag |= (TIOCM_DTR | TIOCM_RTS);

   s = B9600;
   cfsetospeed(&t, (speed_t)s);
   cfsetispeed(&t, (speed_t)s);

   printf("%d\n",tcsetattr(c, actions, &t));
   sleep(1);

   unsigned char request[9] = { 0x10,0x02,0x00,0x00,0x00,0x00,0x10,0x03,0x00 }; // 8 bajtowe (1 char to 1 bajt) żadanie wysyłane do multimetru, dane w tablicy są to liczby zapisane w systemie szesnastkowym (heksadecymalnym), o czym mówi znajdujący się przed nimi "0x"
   unsigned char response[22]; // miejsce na 22 bajtową odpowiedź od multimetru, 22 i bajtów wynikało z pliku instr.doc (PC5000)
   int writtenRequest;

   while (1) { // nieskończona pętla
       for (int i = 0; i < 9; i++) {
           writtenRequest = write(c, &request[i], 1);
         //  printf("writtenRequest: %d\n", writtenRequest);
           nanosleep(&t1, &t2);
       }

       int readResponse = read(c, response, 22); // czytamy dane z otwartego pliku, znowu korzystając z file descriptora, o długości 22 do tablicy response
       printf("Response: %d\n", readResponse);

       if (readResponse == 22) {
               printf("Response: ");
           for (int i = 0; i < readResponse; i++) {
               printf("%c ", response[i]); // Jeśli tak to wypisujemy dane przechowywane w tablicy response
           }
       }
       else {
           printf("Responded number of bytes is diffrent than 22!\n");
       }
   }

   return 0;
}
