#include <EEPROM.h>

// C++ code
//

const int ledVM1 = D10;
const int ledVM2 = D9;
const int ledVM3 = D8;
const int ledAM1 = D7;
const int ledAM2 = D6;
const int ledAM3 = D5;
const int ledVD1 = D4;
const int ledVD2 = D3;
const int ledVD3 = D2;
#define liga HIGH
#define desliga LOW
#define saida OUTPUT
#define entrada INPUT
int continuaEngar = 0;
int ciclo = 0;
int etapaProg = 0;
long int tempoAntigo = 0;

int tempoProg1;
int tempoProg2;
int tempoProg3;
int tempoProg4;
int tempoProg5;
int tempoProg6;
int tempoProg7;
int tempoProg8;
int tempoProg9;
int tempoProg10;
int tempoProg11;
int tempoProg12;
int tempoProg13;
int tempoProg14;
int tempoProg15;
int tempoProg16;
int tempoProg17;
int tempoProg18;
int tempoProg19;
int tempoProg20;
int tempoProg21;
int tempoProg22;
int tempoProg23;
int tempoProg24;
int tempoProg25;
int tempoProg26;
int tempoProg27;
int tempoProg28;
int tempoProg29;
int tempoProg30;
int tempoProg31;
int tempoProg32;
int tempoProg33;
int tempoProg34;

  //tempos do ciclo padrão:
int tempo1 = 20;
int tempo2 = 23;
int tempo3 = 38;
int tempo4 = 41;
int tempo5 = 56;
int tempo6 = 58;
int tempo7 = 59;

//tempos do caso engarrafamento (ledVD2)
int tempo8 = 32;
int tempo9 = 33;
int tempo10 = 3;
int tempo11 = 23;
int tempo12 = 27;
int tempo13 = 42;
int tempo14 = 44;
int tempo15 = 45;

//tempos do caso engarrafamento (ledVD3)
int tempo16 = 50;
int tempo17 = 51;
int tempo18 = 23;
int tempo19 = 27;
int tempo20 = 42;
int tempo21 = 44;
int tempo22 = 45;

//tempos do caso engarrafamento (ledAM2)
int tempo23 = 42;
int tempo24 = 23;
int tempo25 = 27;
int tempo26 = 42;
int tempo27 = 44;
int tempo28 = 45;

//tempos do caso engarrafamento (ledAM3)
int tempo29 = 59;
int tempo30 = 23;
int tempo31 = 27;
int tempo32 = 42;
int tempo33 = 44;
int tempo34 = 45;

void setup() {
  pinMode(ledVM1, saida);
  pinMode(ledVM2, saida);
  pinMode(ledVM3, saida);
  pinMode(ledAM1, saida);
  pinMode(ledAM2, saida);
  pinMode(ledAM3, saida);
  pinMode(ledVD1, saida);
  pinMode(ledVD2, saida);
  pinMode(ledVD3, saida);
EEPROM.begin(4095);
if(EEPROM.read(0) != 0){
  tempo1 = EEPROM.read(0);
  tempo2 = EEPROM.read(1);
  tempo3 = EEPROM.read(2);
  tempo4 = EEPROM.read(3);
  tempo5 = EEPROM.read(4);
  tempo6 = EEPROM.read(5);
  tempo7 = EEPROM.read(6);
  tempo8 = EEPROM.read(7);
  tempo9 = EEPROM.read(8);
  tempo10 = EEPROM.read(9);
  tempo11 = EEPROM.read(10);
  tempo12 = EEPROM.read(11);
  tempo13 = EEPROM.read(12);
  tempo14 = EEPROM.read(13);
  tempo15 = EEPROM.read(14);
  tempo16 = EEPROM.read(15);
  tempo17 = EEPROM.read(16);
  tempo18 = EEPROM.read(17);
  tempo19 = EEPROM.read(18);
  tempo20 = EEPROM.read(19);
  tempo21 = EEPROM.read(20);
  tempo22 = EEPROM.read(21);
  tempo23 = EEPROM.read(22);
  tempo24 = EEPROM.read(23);
  tempo25 = EEPROM.read(24);
  tempo26 = EEPROM.read(25);
  tempo27 = EEPROM.read(26);
  tempo28 = EEPROM.read(27);
  tempo29 = EEPROM.read(28);
  tempo30 = EEPROM.read(29);
  tempo31 = EEPROM.read(30);
  tempo32 = EEPROM.read(31);
  tempo33 = EEPROM.read(32);
  tempo34 = EEPROM.read(33);
  }
  EEPROM.end();
  Serial.begin(9600);
}

void loop() {

  long int tempoAtual = millis();
  long int tempo = (tempoAtual - tempoAntigo);
  int lerLedVD1 = digitalRead(ledVD1);
  int lerLedVD2 = digitalRead(ledVD2);
  int lerLedVD3 = digitalRead(ledVD3);
  int lerLedAM1 = digitalRead(ledAM1);
  int lerLedAM2 = digitalRead(ledAM2);
  int lerLedAM3 = digitalRead(ledAM3);
  int lerLedVM1 = digitalRead(ledVM1);

  if (Serial.available() > 0) {
    String serial = Serial.readString();

    if (serial == "programacao") {
      etapaProg = 0;
      etapaProg++;
      Serial.println("Voce entrou no modo de programacao");
      Serial.println("");
      Serial.println("Para um melhor entendimento do funcionamento do modo de programacao, siga as intruções:");
      Serial.println("1- Se voce quiser retornar para a configuracao inicial digite 'reset'");
      Serial.println("2- Se voce quiser voltar ao inicio do modo de programacao durante o processo dela, digite 'programacao'. Assim voce voltará ao inicio do processo sem que os numeros modificados sejam salvos");
      Serial.println("Tempos iniciais:");
      Serial.println("tempos do ciclo padrão:");
Serial.println("int tempo1 = 20");
Serial.println("int tempo2 = 23");
Serial.println("int tempo3 = 38");
Serial.println("int tempo4 = 41");
Serial.println("int tempo5 = 56");
Serial.println("int tempo6 = 57");
Serial.println("int tempo7 = 58");
Serial.println("");
Serial.println("tempos do caso engarrafamento (ledVD2):");
Serial.println("int tempo8 = 32");
Serial.println("int tempo9 = 33");
Serial.println("int tempo10 = 3");
Serial.println("int tempo12 = 27");
Serial.println("int tempo11 = 23");
Serial.println("int tempo13 = 42");
Serial.println("int tempo14 = 44");
Serial.println("int tempo15 = 45");
Serial.println("");
Serial.println("tempos do caso engarrafamento (ledVD3):");
Serial.println("int tempo16 = 50");
Serial.println("int tempo17 = 51");
Serial.println("int tempo18 = 23");
Serial.println("int tempo19 = 27");
Serial.println("int tempo20 = 42");
Serial.println("int tempo21 = 44");
Serial.println("int tempo22 = 45");
Serial.println("");
Serial.println("tempos do caso engarrafamento (ledAM2):");
Serial.println("int tempo23 = 42");
Serial.println("int tempo24 = 23");
Serial.println("int tempo25 = 27");
Serial.println("int tempo26 = 42");
Serial.println("int tempo27 = 44");
Serial.println("int tempo28 = 45");
Serial.println("");
Serial.println("tempos do caso engarrafamento (ledAM3):");
Serial.println("int tempo29 = 59");
Serial.println("int tempo30 = 23");
Serial.println("int tempo31 = 27");
Serial.println("int tempo32 = 42");
Serial.println("int tempo33 = 44");
Serial.println("int tempo34 = 45;");
    }

    else if (etapaProg == 1 && serial != "engarrafamento" && serial != "reset") {
      tempoProg1 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg1 = ");
      Serial.println(tempoProg1);
    }

    else if (etapaProg == 2 && serial != "engarrafamento" && serial != "reset") {
      tempoProg2 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg2 = ");
      Serial.println(tempoProg2);
    }

    else if (etapaProg == 3 && serial != "engarrafamento" && serial != "reset") {
      tempoProg3 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg3 = ");
      Serial.println(tempoProg3);
    }

    else if (etapaProg == 4 && serial != "engarrafamento" && serial != "reset") {
      tempoProg4 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg4 = ");
      Serial.println(tempoProg4);
    }

    else if (etapaProg == 5 && serial != "engarrafamento" && serial != "reset") {
      tempoProg5 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg5 = ");
      Serial.println(tempoProg5);
    }

    else if (etapaProg == 6 && serial != "engarrafamento" && serial != "reset") {
      tempoProg6 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg6 = ");
      Serial.println(tempoProg6);
    }

    else if (etapaProg == 7 && serial != "engarrafamento" && serial != "reset") {
      tempoProg7 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg7 = ");
      Serial.println(tempoProg7);
    }

    else if (etapaProg == 8 && serial != "engarrafamento" && serial != "reset") {
      tempoProg8 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg8 = ");
      Serial.println(tempoProg8);
    }

    else if (etapaProg == 9 && serial != "engarrafamento" && serial != "reset") {
      tempoProg9 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg9 = ");
      Serial.println(tempoProg9);
    }

    else if (etapaProg == 10 && serial != "engarrafamento" && serial != "reset") {
      tempoProg10 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg10 = ");
      Serial.println(tempoProg10);
    }

    else if (etapaProg == 11 && serial != "engarrafamento" && serial != "reset") {
      tempoProg11 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg11 = ");
      Serial.println(tempoProg11);
    }

    else if (etapaProg == 12 && serial != "engarrafamento" && serial != "reset") {
      tempoProg12 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg12 = ");
      Serial.println(tempoProg12);
    }

    else if (etapaProg == 13 && serial != "engarrafamento" && serial != "reset") {
      tempoProg13 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg13 = ");
      Serial.println(tempoProg13);
    }

    else if (etapaProg == 14 && serial != "engarrafamento" && serial != "reset") {
      tempoProg14 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg14 = ");
      Serial.println(tempoProg14);
    }

    else if (etapaProg == 15 && serial != "engarrafamento" && serial != "reset") {
      tempoProg15 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg15 = ");
      Serial.println(tempoProg15);
    }

    else if (etapaProg == 16 && serial != "engarrafamento" && serial != "reset") {
      tempoProg16 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg16 = ");
      Serial.println(tempoProg16);
    }

    else if (etapaProg == 17 && serial != "engarrafamento" && serial != "reset") {
      tempoProg17 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg17 = ");
      Serial.println(tempoProg17);
    }

    else if (etapaProg == 18 && serial != "engarrafamento" && serial != "reset") {
      tempoProg18 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg18 = ");
      Serial.println(tempoProg18);
    }

    else if (etapaProg == 19 && serial != "engarrafamento" && serial != "reset") {
      tempoProg19 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg19 = ");
      Serial.println(tempoProg19);
    }

    else if (etapaProg == 20 && serial != "engarrafamento" && serial != "reset") {
      tempoProg20 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg20 = ");
      Serial.println(tempoProg20);
    }

    else if (etapaProg == 21 && serial != "engarrafamento" && serial != "reset") {
      tempoProg21 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg21 = ");
      Serial.println(tempoProg21);
    }

    else if (etapaProg == 22 && serial != "engarrafamento" && serial != "reset") {
      tempoProg22 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg22 = ");
      Serial.println(tempoProg22);
    }

    else if (etapaProg == 23 && serial != "engarrafamento" && serial != "reset") {
      tempoProg23 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg23 = ");
      Serial.println(tempoProg23);
    }

    else if (etapaProg == 24 && serial != "engarrafamento" && serial != "reset") {
      tempoProg24 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg24 = ");
      Serial.println(tempoProg24);
    }

    else if (etapaProg == 25 && serial != "engarrafamento" && serial != "reset") {
      tempoProg25 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg25 = ");
      Serial.println(tempoProg25);
    }

    else if (etapaProg == 26 && serial != "engarrafamento" && serial != "reset") {
      tempoProg26 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg26 = ");
      Serial.println(tempoProg26);
    }

    else if (etapaProg == 27 && serial != "engarrafamento" && serial != "reset") {
      tempoProg27 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg27 = ");
      Serial.println(tempoProg27);
    }

    else if (etapaProg == 28 && serial != "engarrafamento" && serial != "reset") {
      tempoProg28 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg28 = ");
      Serial.println(tempoProg28);
    }

    else if (etapaProg == 29 && serial != "engarrafamento" && serial != "reset") {
      tempoProg29 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg29 = ");
      Serial.println(tempoProg29);
    }

    else if (etapaProg == 30 && serial != "engarrafamento" && serial != "reset") {
      tempoProg30 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg30 = ");
      Serial.println(tempoProg30);
    }

    else if (etapaProg == 31 && serial != "engarrafamento" && serial != "reset") {
      tempoProg31 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg31 = ");
      Serial.println(tempoProg31);
    }

    else if (etapaProg == 32 && serial != "engarrafamento" && serial != "reset") {
      tempoProg32 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg32 = ");
      Serial.println(tempoProg32);
    }

    else if (etapaProg == 33 && serial != "engarrafamento" && serial != "reset") {
      tempoProg33 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg33 = ");
      Serial.println(tempoProg33);
    }

    else if (etapaProg == 34 && serial != "engarrafamento" && serial != "reset") {
      tempoProg34 = serial.toInt();
      etapaProg++;
      Serial.println("tempoProg34 = ");
      Serial.println(tempoProg34);
      Serial.print("Digite 'ok' para enviar os valores");
    }

    else if (etapaProg == 35 && serial == "ok" && serial != "reset") {
      tempo1 = tempoProg1;
      Serial.println("tempo1 = ");
      Serial.println(tempo1);
      tempo2 = tempoProg2;
      Serial.println("tempo2 = ");
      Serial.println(tempo2);
      tempo3 = tempoProg3;
      Serial.println("tempo3 = ");
      Serial.println(tempo3);
      tempo4 = tempoProg4;
      Serial.println("tempo4 = ");
      Serial.println(tempo4);
      tempo5 = tempoProg5;
      Serial.println("tempo5 = ");
      Serial.println(tempo5);
      tempo6 = tempoProg6;
      Serial.println("tempo6 = ");
      Serial.println(tempo6);
      tempo7 = tempoProg7;
      Serial.println("tempo7 = ");
      Serial.println(tempo7);
      tempo8 = tempoProg8;
      Serial.println("tempo8 = ");
      Serial.println(tempo8);
      tempo9 = tempoProg9;
      Serial.println("tempo9 = ");
      Serial.println(tempo9);
      tempo10 = tempoProg10;
      Serial.println("tempo10 = ");
      Serial.println(tempo10);
      tempo11 = tempoProg11;
      Serial.println("tempo11 = ");
      Serial.println(tempo11);
      tempo12 = tempoProg12;
      Serial.println("tempo12 = ");
      Serial.println(tempo12);
      tempo13 = tempoProg13;
      Serial.println("tempo13 = ");
      Serial.println(tempo13);
      tempo14 = tempoProg14;
      Serial.println("tempo14 = ");
      Serial.println(tempo14);
      tempo15 = tempoProg15;
      Serial.println("tempo15 = ");
      Serial.println(tempo15);
      tempo16 = tempoProg16;
      Serial.println("tempo16 = ");
      Serial.println(tempo16);
      tempo17 = tempoProg17;
      Serial.println("tempo17 = ");
      Serial.println(tempo17);
      tempo18 = tempoProg18;
      Serial.println("tempo18 = ");
      Serial.println(tempo18);
      tempo19 = tempoProg19;
      Serial.println("tempo19 = ");
      Serial.println(tempo19);
      tempo20 = tempoProg20;
      Serial.println("tempo20 = ");
      Serial.println(tempo20);
      tempo21 = tempoProg21;
      Serial.println("tempo21 = ");
      Serial.println(tempo21);
      tempo22 = tempoProg22;
      Serial.println("tempo22 = ");
      Serial.println(tempo22);
      tempo23 = tempoProg23;
      Serial.println("tempo23 = ");
      Serial.println(tempo23);
      tempo24 = tempoProg24;
      Serial.println("tempo24 = ");
      Serial.println(tempo24);
      tempo25 = tempoProg25;
      Serial.println("tempo25 = ");
      Serial.println(tempo25);
      tempo26 = tempoProg26;
      Serial.println("tempo26 = ");
      Serial.println(tempo26);
      tempo27 = tempoProg27;
      Serial.println("tempo27 = ");
      Serial.println(tempo27);
      tempo28 = tempoProg28;
      Serial.println("tempo28 = ");
      Serial.println(tempo28);
      tempo29 = tempoProg29;
      Serial.println("tempo29 = ");
      Serial.println(tempo29);
      tempo30 = tempoProg30;
      Serial.println("tempo30 = ");
      Serial.println(tempo30);
      tempo31 = tempoProg31;
      Serial.println("tempo31 = ");
      Serial.println(tempo31);
      tempo32 = tempoProg32;
      Serial.println("tempo32 = ");
      Serial.println(tempo32);
      tempo33 = tempoProg33;
      Serial.println("tempo33 = ");
      Serial.println(tempo33);
      tempo34 = tempoProg34;
      Serial.println("tempo34 = ");
      Serial.println(tempo34);
      
      EEPROM.begin(4095);

      EEPROM.write(0, tempo1);
      EEPROM.write(1, tempo2);
      EEPROM.write(2, tempo3);
      EEPROM.write(3, tempo4);
      EEPROM.write(4, tempo5);
      EEPROM.write(5, tempo6);
      EEPROM.write(6, tempo7);
      EEPROM.write(7, tempo8);
      EEPROM.write(8, tempo9);
      EEPROM.write(9, tempo10);
      EEPROM.write(10, tempo11);
      EEPROM.write(11, tempo12);
      EEPROM.write(12, tempo13);
      EEPROM.write(13, tempo14);
      EEPROM.write(14, tempo15);
      EEPROM.write(15, tempo16);
      EEPROM.write(16, tempo17);
      EEPROM.write(17, tempo18);
      EEPROM.write(18, tempo19);
      EEPROM.write(19, tempo20);
      EEPROM.write(20, tempo21);
      EEPROM.write(21, tempo22);
      EEPROM.write(22, tempo23);
      EEPROM.write(23, tempo24);
      EEPROM.write(24, tempo25);
      EEPROM.write(25, tempo26);
      EEPROM.write(26, tempo27);
      EEPROM.write(27, tempo28);
      EEPROM.write(28, tempo29);
      EEPROM.write(29, tempo30);
      EEPROM.write(30, tempo31);
      EEPROM.write(31, tempo32);
      EEPROM.write(32, tempo33);
      EEPROM.write(33, tempo34);
      EEPROM.commit();
      EEPROM.end();

      etapaProg = 0;
      tempoAntigo = millis();
      Serial.println("ENVIO CONCLUIDO - Voce saiu do modo programacao");
    }

    else if(etapaProg != 0 && serial == "reset"){
      
    
 //tempos do ciclo padrão:
tempoProg1 = 20;
tempoProg2 = 23;
tempoProg3 = 38;
tempoProg4 = 41;
tempoProg5 = 56;
tempoProg6 = 58;
tempoProg7 = 59;

//tempos do caso engarrafamento (ledVD2)
tempoProg8 = 32;
tempoProg9 = 33;
tempoProg10 = 3;
tempoProg11 = 23;
tempoProg12 = 27;
tempoProg13 = 42;
tempoProg14 = 44;
tempoProg15 = 45;

//tempos do caso engarrafamento (ledVD3)
tempoProg16 = 50;
tempoProg17 = 51;
tempoProg18 = 23;
tempoProg19 = 27;
tempoProg20 = 42;
tempoProg21 = 44;
tempoProg22 = 45;

//tempos do caso engarrafamento (ledAM2)
tempoProg23 = 42;
tempoProg26 = 42;
tempoProg24 = 23;
tempoProg28 = 45;
tempoProg25 = 27;
tempoProg27 = 44;


//tempos do caso engarrafamento (ledAM3)
tempoProg29 = 59;
tempoProg30 = 23;
tempoProg31 = 27;
tempoProg32 = 42;
tempoProg33 = 44;
tempoProg34 = 45;

etapaProg = 35;
Serial.print("Digite 'ok' para enviar os valores");
    }

     //verifica se há um engarrafamento no semáforo 1 (10 carros ou mais)
    else if (serial == "engarrafamento" && continuaEngar == 0 && tempo >= tempo2 * 1000) {
      continuaEngar = 1;
      if (etapaProg == 0) {
        Serial.println(serial);
      }
    }
  }
   else if (continuaEngar == 1) {

    //Caso engarrafamento com ledVD2 ligado
    if (lerLedVD2 != 0 && ciclo == 0) {

      if (tempo >= tempo2 * 1000 && tempo < tempo8 * 1000) {
        digitalWrite(ledAM1, desliga);
        digitalWrite(ledVM2, desliga);
        digitalWrite(ledVM1, liga);
        digitalWrite(ledVD2, liga);

        if (etapaProg == 0) {
          Serial.println(tempo);
        }
      }

      else if (tempo >= tempo8 * 1000 && tempo <= tempo9 * 1000) {
        tempoAntigo = millis();
        tempoAtual = millis();

        if (etapaProg == 0) {
          Serial.println(tempo);
        }
        ciclo = 1;
      }
    }

    if (ciclo == 1) {
      tempo = (tempoAtual - tempoAntigo);
      if (tempo <= tempo10 * 1000) {
        digitalWrite(ledVD1, desliga);
        digitalWrite(ledVD2, desliga);
        digitalWrite(ledVD3, desliga);
        digitalWrite(ledVM1, liga);
        digitalWrite(ledVM2, desliga);
        digitalWrite(ledVM3, liga);
        digitalWrite(ledAM1, desliga);
        digitalWrite(ledAM2, liga);
        digitalWrite(ledAM3, desliga);

        if (etapaProg == 0) {
          Serial.println(tempo);
        }
      } else if (tempo > tempo10 * 1000 && tempo <= tempo11 * 1000) {
        digitalWrite(ledAM2, desliga);
        digitalWrite(ledVM1, desliga);
        digitalWrite(ledVM2, liga);
        digitalWrite(ledVD1, liga);

        if (etapaProg == 0) {
          Serial.println(tempo);
        }
      } else if (tempo > tempo11 * 1000 && tempo <= tempo12 * 1000) {
        digitalWrite(ledVD1, desliga);
        digitalWrite(ledAM1, liga);

        if (etapaProg == 0) {
          Serial.println(tempo);
        }
      } else if (tempo > tempo12 * 1000 && tempo <= tempo13 * 1000) {
        digitalWrite(ledAM1, desliga);
        digitalWrite(ledVM3, desliga);
        digitalWrite(ledVM1, liga);
        digitalWrite(ledVD3, liga);

        if (etapaProg == 0) {
          Serial.println(tempo);
        }
      } else if (tempo > tempo13 * 1000 && tempo <= tempo14 * 1000) {
        digitalWrite(ledVD3, desliga);
        digitalWrite(ledAM3, liga);

        if (etapaProg == 0) {
          Serial.println(tempo);
        }
      } else if (tempo > tempo14 * 1000 && tempo <= tempo15 * 1000) {
        tempoAntigo = millis();
        continuaEngar = 0;
        ciclo = 0;

        if (etapaProg == 0) {
          Serial.println(tempo);
          Serial.println("continuaEngar = 0");
        }
      }
    }
  

  //Caso engarrafamento com ledVD3 ligado
  else if (lerLedVD3 != 0 && ciclo == 0) {

    if (tempo >= tempo4 * 1000 && tempo < tempo16 * 1000) {
      digitalWrite(ledAM2, desliga);
      digitalWrite(ledVM3, desliga);
      digitalWrite(ledVM2, liga);
      digitalWrite(ledVD3, liga);

      if (etapaProg == 0) {
        Serial.println(tempo);
      }
    }

    else if (tempo >= tempo16 * 1000 && tempo <= tempo17 * 1000) {
      tempoAntigo = millis();
      tempoAtual = millis();

      if (etapaProg == 0) {
        Serial.println(tempo);
      }
      ciclo = 2;
    }
  }
  if (ciclo == 2) {
    tempo = (tempoAtual - tempoAntigo);
    if (tempo <= tempo10 * 1000) {
      digitalWrite(ledVD1, desliga);
      digitalWrite(ledVD2, desliga);
      digitalWrite(ledVD3, desliga);
      digitalWrite(ledVM1, liga);
      digitalWrite(ledVM2, liga);
      digitalWrite(ledVM3, desliga);
      digitalWrite(ledAM1, desliga);
      digitalWrite(ledAM2, desliga);
      digitalWrite(ledAM3, liga);

      if (etapaProg == 0) {
        Serial.println(tempo);
      }
    } else if (tempo > tempo10 * 1000 && tempo <= tempo18 * 1000) {
      digitalWrite(ledAM3, desliga);
      digitalWrite(ledVM1, desliga);
      digitalWrite(ledVM3, liga);
      digitalWrite(ledVD1, liga);

      if (etapaProg == 0) {
        Serial.println(tempo);
      }
    } else if (tempo > tempo18 * 1000 && tempo <= tempo19 * 1000) {
      digitalWrite(ledVD1, desliga);
      digitalWrite(ledAM1, liga);

      if (etapaProg == 0) {
        Serial.println(tempo);
      }
    } else if (tempo > tempo19 * 1000 && tempo <= tempo20 * 1000) {
      digitalWrite(ledAM1, desliga);
      digitalWrite(ledVM2, desliga);
      digitalWrite(ledVM1, liga);
      digitalWrite(ledVD2, liga);

      if (etapaProg == 0) {
        Serial.println(tempo);
      }
    } else if (tempo > tempo20 * 1000 && tempo <= tempo21 * 1000) {
      digitalWrite(ledVD2, desliga);
      digitalWrite(ledAM2, liga);

      if (etapaProg == 0) {
        Serial.println(tempo);
      }
    } else if (tempo > tempo21 * 1000 && tempo <= tempo22 * 1000) {
      tempoAntigo = millis();
      ciclo = 0;
      continuaEngar = 0;

      if (etapaProg == 0) {
        Serial.println(tempo);
        Serial.println("continuaEngar = 0");
      }
    }
  }


//Caso engarrafamento com ledAM2 ligado
else if (lerLedAM2 != 0 && ciclo == 0) {

  if (tempo < tempo4 * 1000) {
    digitalWrite(ledAM1, desliga);
    digitalWrite(ledVM2, desliga);
    digitalWrite(ledVM1, liga);
    digitalWrite(ledVD2, liga);


    if (etapaProg == 0) {
      Serial.println(tempo);
    }
  }

  else if (tempo >= tempo4 * 1000 && tempo <= tempo23 * 1000) {
    tempoAntigo = millis();
    tempoAtual = millis();

    if (etapaProg == 0) {
      Serial.println(tempo);
    }
    ciclo = 4;
  }
}
if (ciclo == 4) {
  tempo = (tempoAtual - tempoAntigo);
  if (tempo <= tempo10 * 1000) {
    digitalWrite(ledVD1, desliga);
    digitalWrite(ledVD2, desliga);
    digitalWrite(ledVD3, desliga);
    digitalWrite(ledVM1, liga);
    digitalWrite(ledVM2, desliga);
    digitalWrite(ledVM3, liga);
    digitalWrite(ledAM1, desliga);
    digitalWrite(ledAM2, liga);
    digitalWrite(ledAM3, desliga);

    if (etapaProg == 0) {
      Serial.println(tempo);
    }
  } else if (tempo > tempo10 * 1000 && tempo <= tempo24 * 1000) {
    digitalWrite(ledAM2, desliga);
    digitalWrite(ledVM1, desliga);
    digitalWrite(ledVM2, liga);
    digitalWrite(ledVD1, liga);

    if (etapaProg == 0) {
      Serial.println(tempo);
    }
  } else if (tempo > tempo24 * 1000 && tempo <= tempo25 * 1000) {
    digitalWrite(ledVD1, desliga);
    digitalWrite(ledAM1, liga);

    if (etapaProg == 0) {
      Serial.println(tempo);
    }
  } else if (tempo > tempo25 * 1000 && tempo <= tempo26 * 1000) {
    digitalWrite(ledAM1, desliga);
    digitalWrite(ledVM3, desliga);
    digitalWrite(ledVM1, liga);
    digitalWrite(ledVD3, liga);

    if (etapaProg == 0) {
      Serial.println(tempo);
    }
  } else if (tempo > tempo26 * 1000 && tempo <= tempo27 * 1000) {
    digitalWrite(ledVD3, desliga);
    digitalWrite(ledAM3, liga);

    if (etapaProg == 0) {
      Serial.println(tempo);
    }
  } else if (tempo > tempo27 * 1000 && tempo <= tempo28 * 1000) {
    tempoAntigo = millis();
    continuaEngar = 0;
    ciclo = 0;

    if (etapaProg == 0) {
      Serial.println(tempo);
      Serial.println("continuaEngar = 0");
    }
  }
}



//Caso engarrafamento com ledAM3 ligado
else if (lerLedAM3 != 0 && ciclo == 0) {

  if (tempo < tempo7 * 1000) {
    digitalWrite(ledAM1, desliga);
    digitalWrite(ledVM2, desliga);
    digitalWrite(ledVM1, liga);
    digitalWrite(ledVD2, liga);

    if (etapaProg == 0) {
      Serial.println(tempo);
    }
  }

  else if (tempo >= tempo7 * 1000 && tempo <= tempo29 * 1000) {
    tempoAntigo = millis();
    tempoAtual = millis();

    if (etapaProg == 0) {
      Serial.println(tempo);
    }
    ciclo = 5;
  }
}
if (ciclo == 5) {
  tempo = (tempoAtual - tempoAntigo);
  if (tempo <= tempo10 * 1000) {
    digitalWrite(ledVD1, desliga);
    digitalWrite(ledVD2, desliga);
    digitalWrite(ledVD3, desliga);
    digitalWrite(ledVM1, liga);
    digitalWrite(ledVM2, liga);
    digitalWrite(ledVM3, desliga);
    digitalWrite(ledAM1, desliga);
    digitalWrite(ledAM2, desliga);
    digitalWrite(ledAM3, liga);

    if (etapaProg == 0) {
      Serial.println(tempo);
    }
  } else if (tempo > tempo10 * 1000 && tempo <= tempo30 * 1000) {
    digitalWrite(ledAM3, desliga);
    digitalWrite(ledVM1, desliga);
    digitalWrite(ledVM3, liga);
    digitalWrite(ledVD1, liga);

    if (etapaProg == 0) {
      Serial.println(tempo);
    }
  } else if (tempo > tempo30 * 1000 && tempo <= tempo31 * 1000) {
    digitalWrite(ledVD1, desliga);
    digitalWrite(ledAM1, liga);

    if (etapaProg == 0) {
      Serial.println(tempo);
    }
  } else if (tempo > tempo31 * 1000 && tempo <= tempo32 * 1000) {
    digitalWrite(ledAM1, desliga);
    digitalWrite(ledVM2, desliga);
    digitalWrite(ledVM1, liga);
    digitalWrite(ledVD2, liga);

    if (etapaProg == 0) {
      Serial.println(tempo);
    }
  } else if (tempo > tempo32 * 1000 && tempo <= tempo33 * 1000) {
    digitalWrite(ledVD2, desliga);
    digitalWrite(ledAM2, liga);

    if (etapaProg == 0) {
      Serial.println(tempo);
    }
  } else if (tempo > tempo33 * 1000 && tempo <= tempo34 * 1000) {
    tempoAntigo = millis();
    continuaEngar = 0;
    ciclo = 0;

    if (etapaProg == 0) {
      Serial.println(tempo);
      Serial.println("continuaEngar = 0");
    }
  }
}
}
  
//Funcionamento padrão
else {
  //ledVD1 ligado
  if (tempo < tempo1 * 1000) {
    digitalWrite(ledVD1, liga);
    digitalWrite(ledVD2, desliga);
    digitalWrite(ledVD3, desliga);
    digitalWrite(ledVM1, desliga);
    digitalWrite(ledVM2, liga);
    digitalWrite(ledVM3, liga);
    digitalWrite(ledAM1, desliga);
    digitalWrite(ledAM2, desliga);
    digitalWrite(ledAM3, desliga);

    if (etapaProg == 0) {
      Serial.println(tempo);
    }
  }

  //ledAM1 ligado
  else if (tempo >= tempo1 * 1000 && tempo < tempo2 * 1000) {
    digitalWrite(ledVD1, desliga);
    digitalWrite(ledAM1, liga);

    if (etapaProg == 0) {
      Serial.println(tempo);
    }
  }

  //ledVD2 ligado
  else if (tempo >= tempo2 * 1000 && tempo < tempo3 * 1000) {
    digitalWrite(ledAM1, desliga);
    digitalWrite(ledVM2, desliga);
    digitalWrite(ledVM1, liga);
    digitalWrite(ledVD2, liga);

    if (etapaProg == 0) {
      Serial.println(tempo);
    }
  }

  //ledAM2 ligado
  else if (tempo >= tempo3 * 1000 && tempo < tempo4 * 1000) {
    digitalWrite(ledVD2, desliga);
    digitalWrite(ledAM2, liga);

    if (etapaProg == 0) {
      Serial.println(tempo);
    }
  }

  //ledVD3 ligado
  else if (tempo >= tempo4 * 1000 && tempo < tempo5 * 1000) {
    digitalWrite(ledAM2, desliga);
    digitalWrite(ledVM3, desliga);
    digitalWrite(ledVM2, liga);
    digitalWrite(ledVD3, liga);

    if (etapaProg == 0) {
      Serial.println(tempo);
    }
  }

  //ledAM3 ligado
  else if (tempo >= tempo5 * 1000 && tempo < tempo6 * 1000) {
    digitalWrite(ledVD3, desliga);
    digitalWrite(ledAM3, liga);

    if (etapaProg == 0) {
      Serial.println(tempo);
    }
  }

  //transformar tempo em 0 para recomeçar o loop
  else if (tempo >= tempo6 * 1000 && tempo <= tempo7 * 1000) {
    tempoAntigo = millis();
    if (etapaProg == 0) {
      Serial.println(tempo);
    }
  }
}
}