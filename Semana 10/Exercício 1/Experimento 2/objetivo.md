# Semana 10 - Aula 04 e 05
## Experimento 2

**Microcontrolador:** ATmega2560

**Objetivos:**
- Configuração dos registradores da interface serial (UART 0) do ATMega2560 para comunicação com o terminal PuTTY.

**Métodos:** A seguir algumas configurações da comunicação UART:
- UART: 8N1. 
-  Baud rate = 9600, considerando um oscilador de 16 MHz da placa. 
-  Registradores utilizados na comunicação UART do microcontrolador ATMega2560 e algumas de suas funções:
- - UCSRnA: contém alguns flags da comunicação RX e TX.
- - UCSRnB: configura alguns bits de habilitação do RX e TX.
- - UCSRnC: configura o formato da comunicação (por ex.: 8N1).
- - UBRRn: configura o baud rate.
- - UDRn: armazena o valor transmitido/recebido.