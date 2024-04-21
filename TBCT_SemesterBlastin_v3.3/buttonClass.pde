/*
Made by: Adam Mangoroban
v1.0
10/11/2022
Description: Adds functionality for addition of buttons and button presses.

Notes: 
 -Put "doButtons()" in the end of main draw function
 -Put any button events in
*/

void checkButtonEvents(String btnName){
  if (!textboxLoading)
  switch(btnName){
    //Add cases for each new button based on btnName
    
    /* EXAMPLE
      case "btnName":
        DO BUTTON EVENT HERE
      break;        
    */
    
    case "eat":
      if(choice != 1){
        choice = 1;
        clearTextBox();
        time -= 1;
        //eatEvent();
      }
      endTask();
    break;
    case "study":
      if(choice != 2){
        choice = 2;
        clearTextBox();
        time -= 1;
        //studyEvent();
      }
      endTask();
    break;
    case "work":
      if(choice != 3){
        choice = 3;
        clearTextBox();
        time -= 2;
        //workEvent();
      }
      endTask();
    break;
    case "relax":
      if(choice != 4){
        choice = 4;
        clearTextBox();
        time -= 1;
        //relaxEvent();
      }
      endTask();
    break;
    
    case "nextAction":
      choice = 0;
      clearTextBox();
      
      btnList.get(0).visible = true;
      btnList.get(1).visible = true;
      if(time >= 2){
        btnList.get(2).visible = true;
      }
      btnList.get(3).visible = true;

      btnList.get(6).visible = false;
      switchBackground();
    break;
    
    case "endDay":
      daySummary();
      dayDone();
    break;
    
    case "nextDay":
      choice = 0;
      time = 3;
      clearTextBox();
      
      btnList.get(0).visible = true;
      btnList.get(1).visible = true;
      btnList.get(2).visible = true;
      btnList.get(3).visible = true;

      btnList.get(5).visible = false;
      switchBackground();
    break;
    
    case "startGame":
    startGame();
    textboxLoading = true;
    switchBackground();
    break;
  }
}

void doButtons(){
  buttonClick();
  checkButtonCollisions();
  drawButtons();  
}

void buttonClick(){
  for(Button b: btnList){
    if(b.clicked && b.visible){
      checkButtonEvents(b.name);
      b.clicked = false;
    }
  }
}

ArrayList<Button> btnList = new ArrayList<Button>();
int btnID = 0;
class Button{
  int xPos;
  int yPos;
  
  int btnWidth;
  int btnHeight;
  
  Boolean visible = true;
  
  int r = 200, g = 200, b = 200;
  
  String name;
  String text = "Button";
  
  Boolean mouseIn = false;
  Boolean clicked = false;
  
  Boolean timeCost = false;
  
  Button(String initName, int initX, int initY, int initWidth, int initHeight, String initText, Boolean vis, Boolean initTimeCost){
    name = initName;
    
    xPos = initX;
    yPos = initY;
    
    btnWidth = initWidth;
    btnHeight = initHeight;
    
    text = initText;
    
    visible = vis;
    
    timeCost = initTimeCost;
    
    btnList.add(this);
  }
  
  Button(String initName, int initX, int initY, int initWidth, int initHeight, String initText, Boolean vis){
    name = initName;
    
    xPos = initX;
    yPos = initY;
    
    btnWidth = initWidth;
    btnHeight = initHeight;
    
    text = initText;
    
    visible = vis;
    
    btnList.add(this);
  }
  
  Button(String initName, int initX, int initY, int initWidth, int initHeight, String initText){
    name = initName;
    
    xPos = initX;
    yPos = initY;
    
    btnWidth = initWidth;
    btnHeight = initHeight;
    
    text = initText;
    
    btnList.add(this);
  }
  
  Button(int initX, int initY, int initWidth, int initHeight, String initText){
    xPos = initX;
    yPos = initY;
    
    btnWidth = initWidth;
    btnHeight = initHeight;
    
    text = initText;
    setID();
    
    btnList.add(this);
  }
  
  Button(int initX, int initY, int initWidth, int initHeight){
    xPos = initX;
    yPos = initY;
    
    btnWidth = initWidth;
    btnHeight = initHeight;
    
    setID();
    
    btnList.add(this);
  }
  
  Button(String initName, int initX, int initY, String initText){
    xPos = initX;
    yPos = initY;
    
    btnWidth = 250;
    btnHeight = 50;
    
    name = initName;
    text = initText;
    
    btnList.add(this);
  }
  
  Button(int initX, int initY){
    xPos = initX;
    yPos = initY;
    
    btnWidth = 250;
    btnHeight = 50;
    
    setID();
    
    btnList.add(this);
  }
  
  void isVisible(Boolean vis){
    visible = vis;
  }
  
  void setID(){
    name = "btn" + btnID;
    btnID++;
  }
}

void drawButtons(){
  for(Button b : btnList){
    if(b.visible){
      fill(b.r * (-.2 * (booltobin(b.mouseIn)) + 1), b.g * (-.2 * (booltobin(b.mouseIn)) + 1), b.b * (-.2 * (booltobin(b.mouseIn)) + 1));
      quad(b.xPos - (b.btnWidth / 2), b.yPos - (b.btnHeight / 2), b.xPos + (b.btnWidth / 2), b.yPos - (b.btnHeight / 2), b.xPos + (b.btnWidth / 2), b.yPos + (b.btnHeight / 2), b.xPos - (b.btnWidth / 2), b.yPos + (b.btnHeight / 2)); 
      
      textAlign(CENTER);
      textSize(16);
      fill(0);
      if(b.timeCost){
        text(b.text, b.xPos, b.yPos - 10); 
      }
      else{
        text(b.text, b.xPos, b.yPos);
      }
    }
  }
}

void checkButtonCollisions(){
  for(Button b : btnList){
    if(b.visible){
      int negX = b.xPos - (b.btnWidth / 2), posX = b.xPos + (b.btnWidth / 2);
      int negY = b.yPos - (b.btnHeight / 2), posY = b.yPos + (b.btnHeight / 2);
      
      float btnArea = b.btnWidth * b.btnHeight;
      
      float t1 = abs(((posX - negX) * (mouseY - negY)) / 2);
      float t2 = abs(((posY - negY) * (mouseX - negX)) / 2);
      float t3 = abs(((posX - negX) * (posY - mouseY)) / 2);
      float t4 = abs(((posY - negY) * (posX - mouseX)) / 2);
      
      b.mouseIn = (btnArea == t1 + t2 + t3 + t4);
      //println(btnArea, t1, t2, t3, t4, t1 + t2 + t3 + t4);
    }
  }
}

void mousePressed(){
  for(Button b: btnList){
    if(b.mouseIn && b.visible){
      //println("Clicked " + b.name);
      b.clicked = true;
    }
  }
}

int booltobin(Boolean input){
  if(input){
    return 1;
  }
  else{
    return 0;
  }
}
