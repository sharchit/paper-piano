#include <CapacitiveSensor.h>

#define speaker 13
CapacitiveSensor cs_C = CapacitiveSensor(2,3);        
CapacitiveSensor cs_D = CapacitiveSensor(2,4);         
CapacitiveSensor cs_E = CapacitiveSensor(2,5);     
CapacitiveSensor cs_F = CapacitiveSensor(2,6);     
CapacitiveSensor cs_G = CapacitiveSensor(2,7);      
CapacitiveSensor cs_A = CapacitiveSensor(2,8);         
CapacitiveSensor cs_B = CapacitiveSensor(2,9);  

#define led_C 10
#define led_D 11
#define led_E 12
#define led_F A0 //analog
#define led_G A1 //analog
#define led_A A2 //analog
#define led_B A3 //analog

int frequency[8][7] = {{32, 37, 41, 44, 49, 55, 62},
                {65, 73, 82, 87, 98, 110, 123},
                {131, 147, 165, 175, 196, 220, 247},
                {262, 294, 330, 349, 392, 440, 494},
                {523, 587, 659, 698, 784, 880, 988},
                {1046, 1175, 1318, 1397, 1568, 1760, 1975},
                {2093, 2349, 2637, 2793, 3136, 3520, 3951},
                {4186, 4699, 5274, 5588, 6272, 7040, 7902}};

char data = '5';
int octave = 0;

char findKeyPressed(int octave) {
  while(1) {
    long total1 = cs_C.capacitiveSensor(100);
    long total2 = cs_D.capacitiveSensor(100);
    long total3 = cs_E.capacitiveSensor(100);
    long total4 = cs_F.capacitiveSensor(100);
    long total5 = cs_G.capacitiveSensor(100);
    long total6 = cs_A.capacitiveSensor(100);
    long total7 = cs_B.capacitiveSensor(100);

    //Serial.println(octave);
    if (total1 > 600) {
      tone(speaker,frequency[octave][0]);
      delay(300);
      
      return 'C';
    }
    else if (total2 > 600) {
      tone(speaker,frequency[octave][1]);
      delay(300);
      
      return 'D';
    }
    else if (total3 > 600) {
      tone(speaker,frequency[octave][2]);
      delay(300);
      
      return 'E';
    }
    else if (total4 > 600) {
      tone(speaker,frequency[octave][3]);
      delay(300);
      return 'F';
    }
    else if (total5 > 600) {
      tone(speaker,frequency[octave][4]);
      delay(300);
      
      return 'G';
    }
    else if (total6 > 600) {
      tone(speaker,frequency[octave][5]);
      delay(300);
      
      return 'A';
    }
    else if (total7 > 600) {
      tone(speaker,frequency[octave][6]);
      delay(300);
      
      return 'B';
    }
    else noTone(speaker);
  }
  return '0';
}

void lightLed(char note) {
  if(note == 'C') digitalWrite(led_C, HIGH);
  if(note == 'D') digitalWrite(led_D, HIGH);
  if(note == 'E') digitalWrite(led_E, HIGH);
  if(note == 'F') analogWrite(led_F, 255);
  if(note == 'G') analogWrite(led_G, 255);
  if(note == 'A') analogWrite(led_A, 255);
  if(note == 'B') analogWrite(led_B, 255);
  else return;
}

void turnoffLed(char note) {
  if(note == 'C') digitalWrite(led_C, LOW);
  if(note == 'D') digitalWrite(led_D, LOW);
  if(note == 'E') digitalWrite(led_E, LOW);
  if(note == 'F') analogWrite(led_F, 0);
  if(note == 'G') analogWrite(led_G, 0);
  if(note == 'A') analogWrite(led_A, 0);
  if(note == 'B') analogWrite(led_B, 0);
}

char song_1_notes[] = {'C', 'C', 'G', 'G', 'A', 'A', 'G', 'F', 'F', 'E', 'E', 'D', 'D', 'C', 'G', 'G', 'F', 'F', 'E', 'E', 'D', 'G', 'G', 'F', 'F', 'E', 'E', 'D'};
char song_2_notes[] = {'E','E', 'E', 'E', 'G', 'C', 'D', 'E', 'F','F', 'F', 'E', 'E', 'E', 'D', 'D', 'E', 'D', 'G', 'E', 'E','E'};
char song_3_notes[] = { 'C', 'C', 'D', 'C', 'F', 'E', 'C', 'C', 'D', 'C', 'G', 'F', 'C', 'C', 'C', 'A', 'F', 'E', 'D', 'A', 'A', 'A', 'F', 'G', 'F'};
char song_4_notes[] = {'F', 'G', 'F', 'C', 'A', 'F', 'G', 'F', 'C', 'A', 'F', 'F', 'F', 'G', 'F', 'G', 'A', 'A', 'A', 'A', 'G', 'F', 'F', 'G', 'F', 'C', 'A', 'F', 'G', 'F', 'C', 'A', 'F', 'G', 'F', 'G', 'A', 'A', 'A', 'A', 'G', 'F', 'F', 'F', 'G', 'F', 'C', 'A', 'F', 'G', 'F', 'G', 'A', 'A', 'A', 'A', 'G', 'F', 'F'};
char song_5_notes[] = {'E', 'D', 'F', 'G', 'C', 'B', 'D', 'E', 'B', 'A', 'C', 'E', 'A'};

void autoPlay(char note, int octave, int d) {
  if(note == 'C')
    tone(speaker,frequency[octave][0]);
  if(note == 'D')
    tone(speaker,frequency[octave][1]);
  if(note == 'E')
    tone(speaker,frequency[octave][2]);
  if(note == 'F')
    tone(speaker,frequency[octave][3]);
  if(note == 'G')
    tone(speaker,frequency[octave][4]);
  if(note == 'A')
    tone(speaker,frequency[octave][5]);
  if(note == 'B')
    tone(speaker,frequency[octave][6]);
  delay(d);
  noTone(speaker);
}

void aiPlaySong1() {

    for(char x: song_1_notes) {
      autoPlay(x, 5, 600);
      lightLed(x);
      delay(75);
      turnoffLed(x);
      delay(225);
    }
  
  data = '1';
  return;
}

void aiPlaySong2() {

    for(char x: song_2_notes) {
      autoPlay(x, 5, 250);
      lightLed(x);
      delay(75);
      turnoffLed(x);
      delay(225);
    }
  
  data = '1';
  return;
}

void aiPlaySong3() {

    for(char x: song_3_notes) {
      autoPlay(x, 5, 300);
      lightLed(x);
      delay(75);
      turnoffLed(x);
      delay(225);
    }
  
  data = '1';
  return;
}

void aiPlaySong4() {

    for(char x: song_4_notes) {
      autoPlay(x, 5, 200);
      lightLed(x);
      delay(75);
      turnoffLed(x);
      delay(225);
    }
  data = '1';
  return;
}

void aiPlaySong5() {

    for(char x: song_5_notes) {
      autoPlay(x, 5, 100);
      lightLed(x);
      delay(75);
      turnoffLed(x);
      delay(225);
    }

  data = '1';
  return;
}

void song_1() {
  int current_note = 0;
  while(current_note < 28) {
    lightLed(song_1_notes[current_note]);
    if(findKeyPressed(6) == song_1_notes[current_note]) {
      turnoffLed(song_1_notes[current_note]);
      delay(75);
      current_note++;
    }
  }
  data = '1';
  return;
}

void song_2() {
  int current_note = 0;
  while(current_note < 22) {
    lightLed(song_2_notes[current_note]);
    if(findKeyPressed(6) == song_2_notes[current_note]) {
      turnoffLed(song_2_notes[current_note]);
      delay(75);
      current_note++;
    }
  }
  data = '1';
  return;
}

void song_3() {
  int current_note = 0;
  while(current_note < 25) {
    lightLed(song_3_notes[current_note]);
    if(findKeyPressed(6) == song_3_notes[current_note]) {
      turnoffLed(song_3_notes[current_note]);
      delay(75);
      current_note++;
    }
  }
  data = '1';
  return;
}

void song_4() {
  int current_note = 0;
  while(current_note < 59) {
    lightLed(song_4_notes[current_note]);
    if(findKeyPressed(5) == song_4_notes[current_note]) {
      turnoffLed(song_4_notes[current_note]);
      delay(75);
      current_note++;
    }
  }
  data = '1';
  return;
}

void song_5() {
  int current_note = 0;
  while(current_note < 13) {
    lightLed(song_5_notes[current_note]);
    if(findKeyPressed(5) == song_5_notes[current_note]) {
      turnoffLed(song_5_notes[current_note]);
      delay(75);
      current_note++;
    }
  }
  data = '1';
  return;
}

void setup() {
  octave=0;
  pinMode(led_C, OUTPUT);
  pinMode(led_D, OUTPUT);
  pinMode(led_E, OUTPUT);
  pinMode(led_F, OUTPUT);
  pinMode(led_G, OUTPUT);
  pinMode(led_A, OUTPUT);
  pinMode(led_B, OUTPUT);
  pinMode(speaker, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()) {
    data = Serial.read();
    octave = data - '1';
  }
  octave = data - '1';
  if(data == 'A') song_1();
  if(data == 'B') song_2();
  if(data == 'C') song_3();
  if(data == 'D') song_4();
  if(data == 'E') song_5();
  
  if(data == 'a') aiPlaySong1();
  if(data == 'b') aiPlaySong2();
  if(data == 'c') aiPlaySong3();
  if(data == 'd') aiPlaySong4();
  if(data == 'e') aiPlaySong5();

  long start = millis();

  long total1 = cs_C.capacitiveSensor(100);
  long total2 = cs_D.capacitiveSensor(100);
  long total3 = cs_E.capacitiveSensor(100);
  long total4 = cs_F.capacitiveSensor(100);
  long total5 = cs_G.capacitiveSensor(100);
  long total6 = cs_A.capacitiveSensor(100);
  long total7 = cs_B.capacitiveSensor(100);

  Serial.print(octave);
  Serial.print("\t");                    

  Serial.print(millis() - start);        
  Serial.print("\t");                    

  Serial.print(total1);                  
  Serial.print("\t");                    
  Serial.print(total2);                  
  Serial.print("\t");                    
  Serial.print(total3);                  
  Serial.print("\t");                    
  Serial.print(total4);                  
  Serial.print("\t");                    
  Serial.print(total5);                  
  Serial.print("\t");                    
  Serial.print(total6);                  
  Serial.print("\t");                    
  Serial.print(total7);                   
  Serial.print("\n");

  if (total1 > 600) {
    tone(speaker,frequency[octave][0]);
    digitalWrite(led_C, HIGH);
    delay(300);
    digitalWrite(led_C, LOW);
    noTone(speaker);
  }
  if (total2 > 600) {
    tone(speaker,frequency[octave][1]);
    digitalWrite(led_D, HIGH);
    delay(300);
    digitalWrite(led_D, LOW);
    noTone(speaker);
  }
  if (total3 > 600) {
    tone(speaker,frequency[octave][2]);
    digitalWrite(led_E, HIGH);
    delay(300);
    digitalWrite(led_E, LOW);
    noTone(speaker);
  }
  if (total4 > 600) {
    tone(speaker,frequency[octave][3]);
    analogWrite(led_F, 255);
    delay(300);
    analogWrite(led_F, 0);
    noTone(speaker);
  }
  if (total5 > 600) {
    tone(speaker,frequency[octave][4]);
    analogWrite(led_G, 255);
    delay(300);
    analogWrite(led_G, 0);
    noTone(speaker);
  }
  if (total6 > 600) {
    tone(speaker,frequency[octave][5]);
    analogWrite(led_A, 255);
    delay(300);
    analogWrite(led_A, 0);
    noTone(speaker);
  }
  if (total7 > 600) {
    tone(speaker,frequency[octave][6]);
    analogWrite(led_B, 255);
    delay(300);
    analogWrite(led_B, 0);
    noTone(speaker);
  }
  
}