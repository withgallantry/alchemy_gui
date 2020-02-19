//<File !Start!>
// FILE: [Interface Menu.c]
// Created by GUIslice Builder version: [0.13.b014]
//
// GUIslice Builder Generated File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<File !End!>
//

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "GUIslice.h"
#include "GUIslice_drv.h"

// Include any extended elements
//<Includes !Start!>
// Include extended elements
#include "elem/XSlider.h"
#include "elem/XTextbox.h"
//<Includes !End!>

// ------------------------------------------------
// Defines for resources
// ------------------------------------------------
#define MAX_PATH  255
//<PathStorage !Start!>
//<PathStorage !End!>

// ------------------------------------------------
// Headers and Defines for fonts
// ------------------------------------------------
//<Fonts !Start!>
#define FONT_DROID_MONO8 "/usr/share/fonts/truetype/droid/DroidSansMono.ttf"
#define FONT_DROID_MONO8 "/usr/share/fonts/truetype/droid/DroidSansMono.ttf"
#define FONT_DROID_MONO18 "/usr/share/fonts/truetype/droid/DroidSansMono.ttf"
//<Fonts !End!>


// ------------------------------------------------
// Defines for resources
// ------------------------------------------------
//<Resources !Start!>
//<Resources !End!>

// ------------------------------------------------
// Enumerations for pages, elements, fonts, images
// ------------------------------------------------
//<Enum !Start!>
enum {E_PG_MAIN};
enum {EN_JOYSTICK_BTN,E_ELEM_TEXT1,E_ELEM_TEXTBOX1,E_TXTSCROLL1};
// Must use separate enum for fonts with MAX_FONT at end to use gslc_FontSet.
enum {E_DROID_MONO18,E_DROID_MONO8,MAX_FONT};
//<Enum !End!>

bool        m_bQuit = false;

// ------------------------------------------------
// Instantiate the GUI
// ------------------------------------------------

// ------------------------------------------------
// Define the maximum number of elements and pages
// ------------------------------------------------
//<ElementDefines !Start!>
#define MAX_PAGE                1

#define MAX_ELEM_PG_MAIN 5                                          // # Elems total on page
#define MAX_ELEM_PG_MAIN_RAM MAX_ELEM_PG_MAIN // # Elems in RAM
//<ElementDefines !End!>

// ------------------------------------------------
// Create element storage
// ------------------------------------------------
// GUI Elements
gslc_tsGui                      m_gui;
gslc_tsDriver                   m_drv;
gslc_tsFont                     m_asFont[MAX_FONT];
gslc_tsPage                     m_asPage[MAX_PAGE];

//<GUI_Extra_Elements !Start!>
gslc_tsElem                     m_asPage1Elem[MAX_ELEM_PG_MAIN_RAM];
gslc_tsElemRef                  m_asPage1ElemRef[MAX_ELEM_PG_MAIN];
gslc_tsXTextbox                 m_sTextbox1;
char                            m_acTextboxBuf1[168]; // NRows=6 NCols=28
gslc_tsXSlider                  m_sTextScroll1;

#define MAX_STR                 100

//<GUI_Extra_Elements !End!>

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Save some element references for direct access
//<Save_References !Start!>
gslc_tsElemRef*  m_pElemTextbox1   = NULL;
gslc_tsElemRef*  m_pTextSlider1    = NULL;
//<Save_References !End!>


// Configure environment variables suitable for display
// - These may need modification to match your system
//   environment and display type
// - Defaults for GSLC_DEV_FB and GSLC_DEV_TOUCH are in GUIslice_config.h
// - Note that the environment variable settings can
//   also be set directly within the shell via export
//   (or init script).
//   - eg. export TSLIB_FBDEVICE=/dev/fb1
void UserInitEnv()
{
#if defined(DRV_DISP_SDL1) || defined(DRV_DISP_SDL2)
  setenv((char*)"FRAMEBUFFER",GSLC_DEV_FB,1);
  setenv((char*)"SDL_FBDEV",GSLC_DEV_FB,1);
  setenv((char*)"SDL_VIDEODRIVER",GSLC_DEV_VID_DRV,1);
#endif

#if defined(DRV_TOUCH_TSLIB)
  setenv((char*)"TSLIB_FBDEVICE",GSLC_DEV_FB,1);
  setenv((char*)"TSLIB_TSDEVICE",GSLC_DEV_TOUCH,1);
  setenv((char*)"TSLIB_CALIBFILE",(char*)"/etc/pointercal",1);
  setenv((char*)"TSLIB_CONFFILE",(char*)"/etc/ts.conf",1);
  setenv((char*)"TSLIB_PLUGINDIR",(char*)"/usr/local/lib/ts",1);
#endif
}

// Define debug message function
static int16_t DebugOut(char ch) { fputc(ch,stderr); return 0; }

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
// Common Button callback
bool CbBtnCommon(void* pvGui,void *pvElemRef,gslc_teTouch eTouch,int16_t nX,int16_t nY)
{
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem* pElem = pElemRef->pElem;

  if ( eTouch == GSLC_TOUCH_UP_IN ) {
    // From the element's ID we can determine which button was pressed.
    switch (pElem->nId) {
//<Button Enums !Start!>
      case EN_JOYSTICK_BTN:
        //TODO- Replace with button handling code
        break;

//<Button Enums !End!>
      default:
        break;
    }
  }
  return true;
}
//<Checkbox Callback !Start!>
//<Checkbox Callback !End!>
//<Keypad Callback !Start!>
//<Keypad Callback !End!>
//<Spinner Callback !Start!>
//<Spinner Callback !End!>
//<Listbox Callback !Start!>
//<Listbox Callback !End!>
//<Draw Callback !Start!>
//<Draw Callback !End!>

// Callback function for when a slider's position has been updated
bool CbSlidePos(void* pvGui,void* pvElemRef,int16_t nPos)
{
  gslc_tsGui*     pGui      = (gslc_tsGui*)(pvGui);
  gslc_tsElemRef* pElemRef  = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem     = pElemRef->pElem;
  int16_t         nVal;

  // From the element's ID we can determine which slider was updated.
  switch (pElem->nId) {
//<Slider Enums !Start!>
    case E_TXTSCROLL1:
      // Fetch the slider position
      nVal = gslc_ElemXSliderGetPos(pGui,m_pTextSlider1);
      //TODO- Replace with slider handling code
      break;

//<Slider Enums !End!>
    default:
      break;
  }

  return true;
}
//<Tick Callback !Start!>
//<Tick Callback !End!>

// ------------------------------------------------
// Create page elements
// - strPath: Path to executable passed in to locate resource files
// ------------------------------------------------
bool InitGUI(char *strPath)
{
  gslc_tsElemRef* pElemRef = NULL;

//<InitGUI !Start!>
  gslc_PageAdd(&m_gui,E_PG_MAIN,m_asPage1Elem,MAX_ELEM_PG_MAIN_RAM,m_asPage1ElemRef,MAX_ELEM_PG_MAIN);
  // NOTE: The current page defaults to the first page added. Here we explicitly
  //       ensure that the main page is the correct page no matter the add order.
  gslc_SetPageCur(&m_gui,E_PG_MAIN);

  
  // Set Background to a flat color
  gslc_SetBkgndColor(&m_gui,GSLC_COL_BLACK);

  // -----------------------------------
  // PAGE: E_PG_MAIN
  
  // Create E_ELEM_TEXT1 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT1,E_PG_MAIN,(gslc_tsRect){187,31,286,43},
    (char*)"Alchemy Stone",0,E_DROID_MONO18);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // create EN_JOYSTICK_BTN button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,EN_JOYSTICK_BTN,E_PG_MAIN,
    (gslc_tsRect){220,115,200,40},(char*)"Enable Joystick",0,E_DROID_MONO8,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE_DK2,GSLC_COL_TEAL,GSLC_COL_GREEN_DK4);
   
  // Create wrapping box for textbox E_ELEM_TEXTBOX1 and scrollbar
  pElemRef = gslc_ElemCreateBox(&m_gui,GSLC_ID_AUTO,E_PG_MAIN,(gslc_tsRect){25,233,201,63});
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,GSLC_COL_BLACK,GSLC_COL_BLACK);
  
  // Create textbox
  pElemRef = gslc_ElemXTextboxCreate(&m_gui,E_ELEM_TEXTBOX1,E_PG_MAIN,&m_sTextbox1,
    (gslc_tsRect){25+2,233+4,201-23,63-7},E_DROID_MONO8,
    (char*)&m_acTextboxBuf1,6,28);
  gslc_ElemXTextboxWrapSet(&m_gui,pElemRef,true);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_YELLOW);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,GSLC_COL_BLACK,GSLC_COL_BLACK);
  m_pElemTextbox1 = pElemRef;

  // Create vertical scrollbar for textbox
  pElemRef = gslc_ElemXSliderCreate(&m_gui,E_TXTSCROLL1,E_PG_MAIN,&m_sTextScroll1,
          (gslc_tsRect){25+201-21,233+4,20,63-8},0,100,0,5,true);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,GSLC_COL_BLACK,GSLC_COL_BLACK);
  gslc_ElemXSliderSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  m_pTextSlider1 = pElemRef;
//<InitGUI !End!>

  return true;
}

int main( int argc, char* args[] )
{
  bool              bOk = true;
  char              acTxt[MAX_STR];

  // ------------------------------------------------
  // Initialize
  // ------------------------------------------------
  gslc_InitDebug(&DebugOut);
  UserInitEnv();
  
  if (!gslc_Init(&m_gui,&m_drv,m_asPage,MAX_PAGE,m_asFont,MAX_FONT)) { exit(1); }

  // ------------------------------------------------
  // Load Fonts
  // ------------------------------------------------
//<Load_Fonts !Start!>
  bOk = gslc_FontSet(&m_gui,E_DROID_MONO18,GSLC_FONTREF_FNAME,FONT_DROID_MONO18,18);
  if (!bOk) { fprintf(stderr,"ERROR: FontAdd failed: %s\n",FONT_DROID_MONO18); exit(1); }
  bOk = gslc_FontSet(&m_gui,E_DROID_MONO8,GSLC_FONTREF_FNAME,FONT_DROID_MONO8,8);
  if (!bOk) { fprintf(stderr,"ERROR: FontAdd failed: %s\n",FONT_DROID_MONO8); exit(1); }
//<Load_Fonts !End!>

  // ------------------------------------------------
  // Create graphic elements
  // ------------------------------------------------
  InitGUI(dirname(args[0])); // Pass executable path to find resource files

  // ------------------------------------------------
  // Start up display on main page
  // ------------------------------------------------
//<Startup !Start!>
//<Startup !End!>

  // ------------------------------------------------
  // Main event loop
  // ------------------------------------------------

  m_bQuit = false;
  while (!m_bQuit) {

    // ----------------------------------------------
    // Update GUI Elements
    // ----------------------------------------------
    
    //TODO - Add update code for any text, gauges, or sliders
  
    // ----------------------------------------------
    // Periodically call GUIslice update function
    // ----------------------------------------------
    gslc_Update(&m_gui);

  } // bQuit

  // ------------------------------------------------
  // Close down display
  // ------------------------------------------------

  gslc_Quit(&m_gui);

  return 0;
}

