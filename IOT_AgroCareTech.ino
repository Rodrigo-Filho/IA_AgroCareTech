#include <SPI.h>
#include <MFRC522.h>
#include <idDHT11.h>

#define RST_PIN         9          // Pino de reset do RFID
#define SS_PIN          10         // Pino de seleção de escravo para o RFID
#define idDHT11pin      2          // Pino do sensor DHT11
#define idDHT11intNumber 0          // Número da interrupção do pino

void dht11_wrapper();  // Declaração da função dht11_wrapper antes da instância

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Instancia o objeto MFRC522
idDHT11 DHT11(idDHT11pin, idDHT11intNumber, dht11_wrapper);  // Instancia o sensor DHT11

bool rfidLido = false;  // Variável para controlar se o RFID já foi lido
bool temperaturaCapturada = false; // Variável para controlar se a temperatura já foi capturada

// Variáveis para os valores do sensor DHT11
float temperaturaC = 0;
float umidade = 0;

void setup() {
    // Inicializa a comunicação serial e os periféricos
    Serial.begin(9600);
    while (!Serial);
    SPI.begin();
    mfrc522.PCD_Init();
    delay(4); 
    Serial.println(F("Aproxime o cartão RFID para iniciar a leitura de temperatura..."));
}

void loop() {
    // Se o cartão RFID já foi lido e a temperatura já foi capturada, não faz mais nada
    if (rfidLido && temperaturaCapturada) {
        return;
    }

    // Verifica se o cartão RFID já foi lido
    if (!rfidLido) {
        // Verifica se há um novo cartão RFID presente
        if (!mfrc522.PICC_IsNewCardPresent()) {
            return;
        }

        // Seleciona o cartão
        if (!mfrc522.PICC_ReadCardSerial()) {
            return;
        }

        // Imprime o UID do cartão
        Serial.print(F("UID do cartão: "));
        for (byte i = 0; i < mfrc522.uid.size; i++) {
            Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
            Serial.print(mfrc522.uid.uidByte[i], HEX);
        }
        Serial.println();

        // Impede a leitura contínua do cartão
        mfrc522.PICC_HaltA();
        rfidLido = true;  // Sinaliza que o cartão já foi lido
        Serial.println(F("Cartão RFID lido com sucesso. Iniciando leitura de temperatura e umidade..."));
    }

    // Se o cartão já foi lido, começa a leitura da temperatura
    if (rfidLido && !temperaturaCapturada) {
        lerTemperaturaEUmidade();

        // Se a temperatura for válida (diferente de 0), para de fazer leituras
        if (temperaturaC > 0) {
            temperaturaCapturada = true;
            Serial.println("Leitura concluída. Temperatura e umidade capturadas.");
        }
    }
}

void lerTemperaturaEUmidade() {
    static unsigned long delayLeitura = millis();
    static bool aquisicaoIniciada = false;

    if ((millis() - delayLeitura) >= 2000 && !aquisicaoIniciada) {  // Faz uma nova leitura a cada 2 segundos
        Serial.println("Iniciando leitura de temperatura e umidade...");

        DHT11.acquire();  // Inicia aquisição de dados do sensor
        aquisicaoIniciada = true;  // Sinaliza que a aquisição foi iniciada
    }

    // Verifica se a leitura foi concluída
    if (aquisicaoIniciada && !DHT11.acquiring()) {
        aquisicaoIniciada = false;  // Resetar flag de aquisição para futuras leituras

        int result = DHT11.getStatus();
        if (result == IDDHTLIB_OK) {
            temperaturaC = DHT11.getCelsius();
            umidade = DHT11.getHumidity();

            // Exibe a temperatura que foi lida
            Serial.print("Leitura concluída com sucesso! Temperatura lida: ");
            Serial.println(temperaturaC);  // Mostra a temperatura junto com a mensagem
            
            Serial.print("Temperatura (C): ");
            Serial.println(temperaturaC);
            Serial.print("Umidade Relativa (%): ");
            Serial.println(umidade);
        } else {
            // Trata os erros na leitura
            Serial.println("Erro na leitura do sensor DHT11.");
            switch (result) {
                case IDDHTLIB_ERROR_CHECKSUM:
                    Serial.println("Erro: Checksum incorreto.");
                    break;
                case IDDHTLIB_ERROR_ISR_TIMEOUT:
                    Serial.println("Erro: Tempo limite ISR atingido.");
                    break;
                case IDDHTLIB_ERROR_RESPONSE_TIMEOUT:
                    Serial.println("Erro: Tempo limite de resposta.");
                    break;
                case IDDHTLIB_ERROR_DATA_TIMEOUT:
                    Serial.println("Erro: Tempo limite de dados.");
                    break;
                case IDDHTLIB_ERROR_ACQUIRING:
                    Serial.println("Erro: Erro de aquisição.");
                    break;
                case IDDHTLIB_ERROR_DELTA:
                    Serial.println("Erro: Tempo delta muito pequeno.");
                    break;
                case IDDHTLIB_ERROR_NOTSTARTED:
                    Serial.println("Erro: Aquisição não iniciada.");
                    break;
                default:
                    Serial.println("Erro desconhecido.");
                    break;
            }
        }
        delayLeitura = millis();  // Atualiza o tempo para a próxima tentativa de leitura
    }
}

void dht11_wrapper() {
    DHT11.isrCallback();  // Função de interrupção para o DHT11
}
