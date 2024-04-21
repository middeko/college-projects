/*Semester Blast'n
Made by the TBCT
SC, AM, FK, GI, WD
11/16/22
Description: A visual novel experience with a twist top-down shooter gameplay
*/
int happyStat = 70;    //calculated level of happiness the player has

int gradeStat = 70;    //calculated overall grade the player has

int wealthStat = 40;   //amount of money the player has

int hungerStat = 70;  //how hungery the player is

int choice = 0; //the value for each choice

int time = 3; // the value for energy the player has for the day

int day = 1; //number of days that have passed

int last = 0; //checks if the scene changes
boolean change = false;

boolean textboxLoading = false; //checks if the text box is still loading


int widthInc = 0; //the width of the text box
boolean textReady = false; //checks if the text box is loaded for the text

//initializing the images
PImage demoBackground;
PImage Campus;
PImage DinningHall;
PImage dHall;
PImage library;
PImage Work;
PImage Relax;
PImage MainMenu;


void setup() {
  size(720, 576);
  //loading the images for the scenes
  demoBackground = loadImage("testBackground.png");
  dHall = loadImage ("Dinning Hall.png");
  library = loadImage ("Library.png");
  Work = loadImage ("Work.png");
  Relax = loadImage ("Relax.png");
  Campus = loadImage ("Campus.png");
  DinningHall = loadImage ("DinningHall.png");
  MainMenu = loadImage ("MainMenu.png");
  createTextButtons(); //creates buttons and places them on the screen
  switchBackground(); //switches the background when a choice is made
  mainMenu();
}

void draw() {
  //checks if the scene changes
  if (last != choice) {
    change = true;
    last = choice;
  }
  //if the scene changes, load next background
  if (change == true) {
    switchBackground();
    change = false;
  }
  //changes the size of the text box
  if (textboxLoading) {
    drawTextbox();
  }

  doButtons(); //checks for the button inputs
}

//displays the day's results
void dayDone() {
  textSize(50);
  fill(255);
  text("Day " + day + " done" , width/2 - 100, 40);
  btnList.get(5).visible = true;

  text("Happiness: " + happyStat + "\nGrade: " + gradeStat + "\nWealth: $" + wealthStat + "\nHunger: " + hungerStat, width/2-200, 200);
  day = day + 1;
}

//creates all of the interactive buttons
void createTextButtons() {
  //Button(id name, X pos, Y pos, Width, Height, Text, isVisible)
  new Button("relax", 550, 470, 100, 50, "Relax\n1©", false, true);
  new Button("study", 660, 470, 100, 50, "Study\n1©", false, true);
  new Button("work", 550, 540, 100, 50, "Work\n2©", false, true);
  new Button("eat", 660, 540, 100, 50, "Eat\n1©", false, true);

  new Button("endDay", 605, 505, 210, 120, "End Day", false);

  new Button("nextDay", width / 2, 526, 200, 50, "Next Day", false);
  
  new Button("nextAction", 605, 505, 210, 120, "Next", false);
  new Button("startGame", width / 2, 526, 200, 50, "START", true);
  
}

//clears the text box for new text
void clearTextBox() {
  background(255);
  textboxLoading = true;
  textReady = false;
  widthInc = 0;
}

//changes the button's visibility after the player choose a choice
void endTask() {
  btnList.get(0).visible = false;
  btnList.get(1).visible = false;
  btnList.get(2).visible = false;
  btnList.get(3).visible = false;
  btnList.get(7).visible = false;

  if(time > 0){
    btnList.get(6).visible = true;
  }
  else{
    btnList.get(4).visible = true; 
  }
}

void startGame(){
  btnList.get(0).visible = true;
  btnList.get(1).visible = true;
  btnList.get(2).visible = true;
  btnList.get(3).visible = true;
  btnList.get(7).visible = false;
}

//sets the background to black after hiding the end day button
void daySummary() {
  btnList.get(4).visible = false;
  background(0);
}

//switches the background to the specific scene the player chooses
void switchBackground() {
  image(Campus, 0, 0);
  if (choice == 1) {
    image(DinningHall, 0, 0);
  }
  if (choice == 2) {
    image(library, 0, 0);
  }
  if (choice == 3) {
    image(Work, 0, 0);
  }
  if (choice == 4) {
    image(Relax, 0, 0);
  }
}

//calculates the stat gains and loses after a choice is made
void changeStats(int deltaGrade, int deltaHappiness, int deltaWealth, int deltaHunger) {
  gradeStat += deltaGrade;
  happyStat += deltaHappiness;
  wealthStat += deltaWealth;
  hungerStat += deltaHunger;
}

//the events that occurs after each choice the player makes
void workEvent(Boolean spec) {
  changeStats(0, -10, 10, -25);
  //lose 2 time
  //lose 10 happiness
  //gain $10
  //lose 25 hunger points
}

void studyEvent(Boolean spec) {
  if(!spec){
    changeStats(5, -5, 0, -10); 
  }
  else{
    changeStats(5, 10, 0, -10); 
  }
  //lose 1 time
  //gain 5 grade points
  //lose -5 happiness points
  //lose 10 hunger points
}

void relaxEvent(Boolean spec) {
  changeStats(-10, 10, 0, -20);
  //lose 1 time
  //lose 10 grade points 
  //gain 10 happiness points
  //lose 20 hunger points
}

void eatEvent(Boolean spec) {
  if(!spec){
    changeStats(0, 5, -8, 20); 
  }
  else{
    changeStats(0, 20, -8, 20);
  }
  //lose 1 time
  //gain 5 happiness
  //lose 8 dollars
  //gain 20 hunger points
}

String getWeekDay(int day){
  int p = (day - 1) % 3;
  switch(p){
    case 0:
      return "Monday";
    case 1:
      return "Wednesday";
    case 3:
      return "Friday";
  }
  
  return "error";
}

//draws the text box containing text on the screen
void drawTextbox() {
  fill(#FFFFFF);
  rect(0, 428, widthInc, 150);

  if (widthInc < 720) {
    widthInc += 10;
  } else if (widthInc >= 720) {
    textReady = true;
    textboxLoading = false;
  }

  if (textReady == true) {
    textAlign(LEFT);
    fill(#030101);
    textSize(25);
    int rng = (int)(random(1) * 100);
    println(time);
    Boolean isSpecial = null;
    if (choice == 0) {
      if((day - 1) % 3 == 0){
        text("Today is " + getWeekDay(day) + ", the test is on Friday\nYou have " + time + "© actions.\nHow will you spend your day?", 20, 475); 
      }
      else if((day - 1) % 3 == 1){
        text("Today is " + getWeekDay(day) + ", the test is the next day!!!\nYou have " + time + "© actions.\nHow will you spend your day?", 20, 475); 
      }
    }
    if (choice == 1) {
      if(rng > 20){ //20% chance for filipino event
        text("You had food at the dinning hall\nYou gained: " + 5 + " Happiness and " + 20 + " Hunger\nYou paid $" + 8, 20, 475);
        isSpecial = false;
      }
      else{
        text("The Filipino food reminds you of home\nYou gained: " + 20 + " Happiness and " + 20 + " Hunger\nYou paid $" + 8, 20, 475);
        isSpecial = true;
      }
      eatEvent(isSpecial);
    }
    if (choice == 2) {
      if(rng > 20){ //20% chance for friend event
        text("You studied in the library.\nYour grade increased by: " + 5 + " points.\nYou lost " + 5 + " Happiness and " + 10 + " Hunger", 20, 475);
        isSpecial = false;
      }
      else{
        text("You studied in the library with friends.\nYou gain " + 5 + " grades and " + 10 +" Happpiness.\nYou lost " + 10 + " Hunger", 20, 475);
        isSpecial = true;
      }
      studyEvent(isSpecial);
    }
    if (choice == 3) {
      text("You went to work.\nYou got " + 10 + " dollars. \nYou lost " + 10 +" happiness and " + 25 + " hunger points.", 20, 475);
      isSpecial = false;
      workEvent(isSpecial);
    }
    if (choice == 4) {
      text("You went and took a nap!\nYou gained " + 10 + " happiness.\nYou lost " + 10 + " grade points and " + 20 + " hunger points.", 20, 475);
      isSpecial = false;
      relaxEvent(isSpecial);
    }
    textReady = false;
  }
}

void mainMenu(){
  image(MainMenu, 0, 0);
  
}
