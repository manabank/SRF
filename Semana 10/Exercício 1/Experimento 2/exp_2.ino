void setup() {
  
  DDRE = DDRE | B00000010; //RE1 (pino TX0) = saída

  UCSR0A = 0x00; //Limpa flags TXC RXC; Configura para velocidade normal.

  UCSR0C = 0b00000110; // Formato: UART assíncrono - 8N1.
  UCSR0B = (1<<TXEN0); // Habilita TX.

  UBRR0 = 103; // Baud rate 9600 bps (16 MHz; U2X (veloc normal)).
}

void loop() {
  
  // Aguardando o buffer de transmissão vazio.
  while (!(UCSR0A & (1<<UDRE0))){};
  UDR0 = 0x4F; // Enviando o caractere ‘O'.

  while (!(UCSR0A & (1<<UDRE0))){};
  UDR0 = 0x69; // Enviando o caractere ‘i'.

  while (!(UCSR0A & (1<<UDRE0))){};
  UDR0 = 0x21; // Enviando o caractere '!'.

  delay(2000);
}
