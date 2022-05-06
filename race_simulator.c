#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section
struct Race {
  int numberOfLaps;
  int currentLap;
  char* firstPlaceDriverName;
  char* firstPlaceRaceCarColor;
};

struct RaceCar {
  char* driverName;
  char* raceCarColor;
  int totalLapTime;
};

// Print functions section
void printIntro() {
  printf("------------------------------\n");
  printf("Welcome to our main event\n");
  printf("digital race fans!\n");
  printf("I hope everybody has their\n");
  printf("snacks because we are about to\n");
  printf("begin!\n");
  printf("------------------------------\n");
}

void printCountDown() {
  printf("Racers Ready! In...\n");
  printf("5\n");
  printf("4\n");
  printf("3\n");
  printf("2\n");
  printf("1\n");
  printf("Race!\n");
  printf("------------------------------\n");
}

void printFirstPlaceAfterLap(struct Race race) {
  printf("After lap number %d\n", race.currentLap);
  printf("First place is: %s in the\n", race.firstPlaceDriverName);
  printf("%s race car!\n", race.firstPlaceRaceCarColor);
  printf("------------------------------\n");
}

void printCongratulation(struct Race race) {
  printf("Let's all congratulate %s\n", race.firstPlaceDriverName);
  printf("in the %s race car for an\n", race.firstPlaceRaceCarColor);
  printf("amazing performance.\n");
  printf("It truly was a great race and\n");
  printf("everybody have a goodnight!\n");
  printf("------------------------------\n");
}

// Logic functions section
int calculateTimeToCompleteLap() {
  int speed = (rand() % 3) + 1;
  int acceleration = (rand() % 3) + 1;
  int nerves = (rand() % 3) + 1;
  return speed + acceleration + nerves;
}

void updateRaceCar(struct RaceCar* raceCar) {
  raceCar->totalLapTime += calculateTimeToCompleteLap();
}

void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  if (raceCar1->totalLapTime <= raceCar2->totalLapTime) {
    race->firstPlaceDriverName = raceCar1->driverName;
    race->firstPlaceRaceCarColor = raceCar1->raceCarColor;
  } else {
    race->firstPlaceDriverName = raceCar2->driverName;
    race->firstPlaceRaceCarColor = raceCar2->raceCarColor;
  }
}

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  struct Race race = {5, 1, "", ""};
  for(int i = 0; i < race.numberOfLaps; i++) {
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);
    race.currentLap += 1;
  }
  printCongratulation(race);
}

int main() {
	srand(time(0));

  struct RaceCar raceCar1 = {"Andrew", "Red", 0};
  struct RaceCar raceCar2 = {"Abigail", "Blue", 0};
  
  printIntro();
  printCountDown();
  startRace(&raceCar1, &raceCar2);

  return 0;
};