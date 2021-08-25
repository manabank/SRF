void setup() {
  DDRH = DDRH | B00000010; // Configura RH1 como saída (pino TX)

  UCSR2A = 0x00; // Limpa flags TXC RXC; Configura para velocidade normal.
  
  UCSR2C = 0b00000110; // Formato: UART assíncrono - 8N1
  UCSR2B = (1<<TXEN0); // Habilita TX
  
  UBRR2 = 103; // Baud rate 9600 bps (16 MHz; U2X (veloc normal))
}

void loop() {
  while (!(UCSR2A & (1<<UDRE2))){};
  UDR2 = 0x61; // 'a'
  delay(1000);
  
  while (!(UCSR2A & (1<<UDRE2))){};
  UDR2 = 0x62; // 'b'
  delay(1000);
  
  while (!(UCSR2A & (1<<UDRE2))){};
  UDR2 = 0x63; // 'c'
  delay(1000);

  while (!(UCSR2A & (1<<UDRE2))){};
  UDR2 = 0x64; // 'd'
  delay(1000);
}
