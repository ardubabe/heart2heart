#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2); // I2C address 0x20, 16 column and 2 rows

const int buttonPin = 10;
int buttonState = 0;
int prevButtonState = 0;
int reply;

int red_light_pin = 13;
int green_light_pin = 12;
int blue_light_pin = 11;

void setup() {

  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);

  lcd.init(); // initialize the lcd
  lcd.backlight();

  pinMode(buttonPin, INPUT);

  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("Press button for");        // print message at (0, 0)
  lcd.setCursor(0, 1);         // move cursor to   (2, 1)
  lcd.print("a question!"); // print message at (2, 1)

  analogWrite(red_light_pin,  0);
  analogWrite(green_light_pin,  255);
  analogWrite(blue_light_pin,  255);


}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState != prevButtonState) {
    if (buttonState == HIGH) {
      reply = random(3);

      lcd.clear();
      lcd.setCursor(0, 0);

      switch (reply) {
        case 0:
          lcd.print("What's your");
          lcd.setCursor(0, 1);
          lcd.print("starsign?");
          RGB_color(256-2, 256-245, 256-217); // Cyan
          break;
        case 1:
          lcd.print("What's your");
          lcd.setCursor(0, 1);
          lcd.print("love language?");
          RGB_color(256-108, 256-66, 256-245); // Cyan
          break;
        case 2:
          lcd.print("what's your");
          lcd.setCursor(0, 1);
          lcd.print("attachment style?");
          RGB_color(256-209, 256-245, 256-2); // Raspberry
          break;
      }
    }
  }

  prevButtonState = buttonState;
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
{
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
