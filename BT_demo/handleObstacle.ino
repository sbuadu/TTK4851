void handleObstacle(int distance1, int distance2, int minimumRange1, int maximumRange2){
  reverse(800);
  if (distance2 >= maximumRange2){
    turnLeft(750);
    goForward();
    delay(600);
    stopMotors();
    } 
  else if (distance1 <= minimumRange1){
    turnRight(750);
    goForward();
    delay(600);
    stopMotors();
    }
  }
