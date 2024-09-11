// Define the PIDController class
class PIDController {
   private:
    double SetPoint, kp, ki, kd=0 ;
    unsigned long currentTime, previousTime =0;
    double elapsedTime, error, lastError, cumError, rateError;
    double input ,output;     
    //soft starter 
    double alpha , preValue ;   //smoothing factor,previous filtered value


  public:
    PIDController(double kp, double ki, double kd) 
      : kp(kp), ki(ki), kd(kd), cumError(0), lastError(0), previousTime(0), alpha(0.0), preValue(0.0) {}
    
    void setSP(double SetPoint) {            //SET POINT 
      this->SetPoint = SetPoint;
    }

    void setAlpha(double alpha) {          // Set alpha(SMOOTHING FACTOR)   
      this->alpha = alpha;
    }
    
    // Calculate the PID output
    double compute(double input) {
      unsigned long currentTime = millis();                              //how much time has based for every single loop
      double elapsedTime = (currentTime - previousTime) / 1000.00;       // Elapsed time (dt)

      if (elapsedTime <= 0) return 0;                                    // Prevent division by zero
    
      double error = SetPoint - input;
      cumError += error * elapsedTime;                              // Compute integral (I) of the error
      double rateError = (error - lastError) / elapsedTime;         // Compute derivative (D) of the error
      double output = kp * error + ki * cumError + kd * rateError;  // Compute PID output
      
      lastError = error;
      previousTime = currentTime;
      
      // Apply exponential smoothing filter
      double filteredValue = alpha * input + (1 - alpha) * preValue;
      preValue = filteredValue;
      
      return output;
    }

};

const int inPIN = A0;
const int outPIN = 3;

PIDController pid(2.0, 5.0, 1.0);     //instance of PIDController    

void setup() {

  pinMode(inPIN, INPUT);
  pinMode(outPIN, OUTPUT);
  pid.setAlpha(0.1);                  
  pid.setSP(128);                    
}

void loop() {
  double input = map(analogRead(inPIN), 0, 1023, 0, 255);  // mapping input value for PWM signal
  double output = pid.compute(input);                      //  PID output
  analogWrite(outPIN, output);                             // Apply output to PWM pin
}