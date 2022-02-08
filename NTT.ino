const int l_playerOne = 2;    //Pin do którego podłączona jest dioda odpowiadająca pierwszemu graczowi
const int l_playerTwo = 6;    //Pin do którego podłączona jest dioda odpowiadająca drugiemu graczowi
const int l_playerThree = 8;  //Pin do którego podłączona jest dioda odpowiadająca trzeciemu graczowi
const int l_playerFour = 11;  //Pin do którego podłączona jest dioda odpowiadająca czwartemu graczowi
const int b_playerOne = 3;    //Pin do którego podłączony jest przycisk odpowiadający pierwszemu graczowi
const int b_playerTwo = 4;    //Pin do którego podłączony jest przycisk odpowiadający drugiemu graczowi
const int b_playerThree = 9;  //Pin do którego podłączony jest przycisk odpowiadający trzeciemu graczowi
const int b_playerFour = 10;  //Pin do którego podłączony jest przycisk odpowiadający czwartemu graczowi
const int b_game = 5;         //Pin do którego podłączony jest przycisk odpowiadający prowadzącemu

bool musicPlays = false;      //zmienna informuja czy telefon aktualnie odtwarza muzykę

void setup() {
  //inicjalizacja pinów do których podłączone są diody na wyjście
  pinMode(2, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  //inicjalizacja pinów do których podłączone są przyciski na wejście z rezystorem podciągającym
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  //inicjalizcja połączenia bluetooth
  Serial.begin(9600);
}

void loop() {

  //jeśli przycisk pierwszego gracza został wciśnięty oraz muzyka jest odtwarzana
  if (digitalRead(b_playerOne) == LOW && musicPlays == true) 
      {
        digitalWrite(l_playerOne, HIGH);//zaświecenie diody odpowiadającej pierwszemu graczowi
        musicPlays = false;             //zatrzymanie odtwarzania muzyki
        Serial.println("stop\n");       //wysłanie do telefonu sygnału o zatrzymaniu odtwarzania muzyki
      }

  //jeśli przycisk drugiego gracza został wciśnięty oraz muzyka jest odtwarzana
  if (digitalRead(b_playerTwo) == LOW && musicPlays == true) 
      {
        digitalWrite(l_playerTwo, HIGH);//zaświecenie diody odpowiadającej drugiemu graczowi
        musicPlays = false;             //zatrzymanie odtwarzania muzyki
        Serial.println("stop\n");       //wysłanie do telefonu sygnału o zatrzymaniu odtwarzania muzyki
      }

  //jeśli przycisk trzeciego gracza został wciśnięty oraz muzyka jest odtwarzana
  if (digitalRead(b_playerThree) == LOW && musicPlays == true) 
      {
        digitalWrite(l_playerThree, HIGH);//zaświecenie diody odpowiadającej trzeciemu graczowi
        musicPlays = false;               //zatrzymanie odtwarzania muzyki
        Serial.println("stop\n");         //wysłanie do telefonu sygnału o zatrzymaniu odtwarzania muzyki
      }
      
  //jeśli przycisk czwartego gracza został wciśnięty oraz muzyka jest odtwarzana
  if (digitalRead(b_playerFour) == LOW && musicPlays == true) 
      {
        digitalWrite(l_playerFour, HIGH);//zaświecenie diody odpowiadającej czwartemu graczowi
        musicPlays = false;              //zatrzymanie odtwarzania muzyki
        Serial.println("stop\n");        //wysłanie do telefonu sygnału o zatrzymaniu odtwarzania muzyki
      }
      
  //jeśli przycisk prowadzącego został wciśnięty
  if (digitalRead(b_game) == LOW) 
      {
        digitalWrite(l_playerOne, LOW);   //zgaszenie diody pierwszego gracza
        digitalWrite(l_playerTwo, LOW);   //zgaszenie diody drugiego gracza
        digitalWrite(l_playerThree, LOW); //zgaszenie diody trzeciego gracza
        digitalWrite(l_playerFour, LOW);  //zgaszenie diody czwartego gracza
        musicPlays = true;                //odtwarzanie muzyki
        Serial.println("start\n");        //wysłanie do telefonu sygnału o rozpoczęciu odtwarzania muzyki
      }
}
