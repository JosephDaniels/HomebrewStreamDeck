/* this will read the buttons on D9-D11
 *  
 *  
 */
//#include <Serial>

// STATE MACHINE VARIABLES FOR DEBOUNCING

const int WAIT_FOR_PRESS = 0; // DEFAULT BUTTON STATE
const int DEBOUNCING = 1; // STATE WHILE DEBOUNCING
const int WAIT_FOR_RELEASE = 2; // STATE AFTER PRESSED

// DEBOUNCING

const int DEBOUNCE_PERIOD = 50; // LENGTH OF TIME FOR DEBOUNCE

class Debounced{
  public:
    Debounced(int button_pin, char* button_name, int led_pin);
    void tick();
  private:
    char* button_name;
    int button_state;
    int button_timer;
    int led_pin;
    int button_pin;
    bool toggle_status;
};

Debounced::Debounced(int button_pin, char* button_name, int led_pin) {
  this->button_pin=button_pin;
  this->button_name=button_name;
  this->led_pin=led_pin;
  this->toggle_status=false;

  pinMode(button_pin, INPUT_PULLUP);
  pinMode(led_pin, OUTPUT);
  this->button_state = WAIT_FOR_PRESS;
}

void Debounced::tick() {
  // READ BUTTON STATUS
  if (this->button_state == WAIT_FOR_PRESS){
      if (!digitalRead(this->button_pin) == true){
        this->button_timer = DEBOUNCE_PERIOD;
        this->button_state = DEBOUNCING;
        this->toggle_status = !(this->toggle_status);
        Serial.print(this->button_name);
        if (this->toggle_status){ // LED IS ON
          Serial.println (" ON");
        }
        else {
          Serial.println(" OFF");
        }
        digitalWrite(this->led_pin, this->toggle_status);
      }
  }else if (this->button_state == DEBOUNCING){
    if (this->button_timer > 0){
      this->button_timer-=1;
    }else{ // TIMER ELAPSED
      this->button_state = WAIT_FOR_RELEASE;
    }
  }else if (this->button_state == WAIT_FOR_RELEASE){
    if (!digitalRead(this->button_pin) == false){ // BUTTON RELEASED
      this->button_state = WAIT_FOR_PRESS;
    }
  }else {
    Serial.println ("A demon occurred, wut do??! PANIC??");
  }
}

Debounced button1 = Debounced(8, "red button", 11);
Debounced button2 = Debounced(9, "blue button", 12);
Debounced button3 = Debounced(10, "yellow button", 13);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  button1.tick();
  button2.tick();
  button3.tick();
  delay(1);
}
