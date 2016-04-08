/* Διαβάστε τον κώδικα, προσπαθήστε να καταλάβετε τι κάνει από μόνοι σας (σκοπίμως δεν έχουν μπει σχόλια που να εξηγούν
  τι κάνουν οι διάφορες εντολές) και μετά γράψτε μόνοι σας το υπόλοιπο πρόγραμμα με τις οδηγίες που θα βρείτε στα σχόλια.
  Χρησιμοποιήστε της μεταβλητές αληθείας (boolean) ώστε οι εντολές της κάθε κατάστασης (state) να εκτελούνται μόνο μια φορά.
  Ο σκοπός σας είναι, να τελειώσετε το πρόγραμμα στο σπίτι και όταν το δοκιμάσετε στο αμαξάκι, το αμαξάκι να επιδείξει
  την εξής συμπεριφορά:
  Θα προχωρήσει περίπου 20 εκατοστά και θα στρίψει 180 μοίρες (αυτό είναι ήδη έτοιμο για εσάς).
  Θα προχωρήσει ΕΠΙΠΛΕΟΝ περίπου 60 εκατοστά (δηλαδή πόσα απ' την αρχή της λειτουργίας του;) και θα στρίψει 90 μοίρες προς
  τα αριστερά...
  Τέλος, θα συνεχίσει να κινείται ευθεία, μέχρι να διανύσει συνολικά (από την αρχή δηλαδή της λειτουργίας του) 150 εκατοστά. */
#include <Smartcar.h>

Odometer encoderLeft(93), encoderRight(93); //Βάλτε τους δικούς σας παλμούς ανά μέτρο
Gyroscope gyro(18); //Βάλτε την κατάλληλη τιμή σύμφωνα με το γυροσκόπιό σας
Car folkracer;
boolean state1Done = false;
boolean state2Done = false;

void setup() {
  gyro.attach();
  encoderLeft.attach(3); //Χρησιμοποιήστε τα σωστά pins!
  encoderRight.attach(2);
  encoderLeft.begin();
  encoderRight.begin();
  gyro.begin();
  folkracer.begin(encoderLeft, encoderRight, gyro);
  folkracer.enableCruiseControl();
  folkracer.setSpeed(0.5);
}

void loop() {
  folkracer.updateMotors();
  unsigned long distance = encoderLeft.getDistance();
  distance = distance + encoderRight.getDistance();
  if (distance > 20 && distance < 30 && state1Done == false) {
    folkracer.stop();
    folkracer.rotate(180);
    folkracer.setSpeed(0.5);
    state1Done = true;
  }
  if (distance > 60 && distance < 70 && state2Done == false) {
    folkracer.stop();
    folkracer.rotate(90);
    folkracer.setSpeed(0.5);
    state2Done = true;
  }
  if (distance > 150) {
    folkracer.stop();
  }
}
