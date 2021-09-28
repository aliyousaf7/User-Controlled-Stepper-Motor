
#include <Stepper.h>
#include <LiquidCrystal.h>
 

const float STEPS_PER_REV = 32; 

const float GEAR_RATIO = 64;
 
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RATIO;

int StepsRequired;;
int sp;
int steps;

Stepper steppermotor(STEPS_PER_REV, 9, 8, 7, 6);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(115200);
}
 
void loop()
{
  
    
    while (Serial.available()) {
      Serial.println("Enter Speed");
      sp = Serial.parseInt();
      steppermotor.setSpeed(sp);
    
      delay(2000);
      
      Serial.println("Enter degrees");
      steps = Serial.parseInt();
      
      steppermotor.step(steps*5.69);

      lcd.setCursor(0,0);
      lcd.print("RPM:");
      lcd.print(sp);
      lcd.setCursor(1,1);
      lcd.print("Degree:");
      lcd.print(steps);
      delay(5000);
                    
    }
  
 
}
