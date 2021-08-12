void setup() {
  // Abre a porta serial a 19200 bps:
  
  Serial.begin(19200);
}

void loop() {
  
  // Imprime dados na porta serial:
  
  Serial.println("Oi!");
  
  delay(1000);
}
