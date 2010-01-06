#ifndef _OF_EVENTS
#define _OF_EVENTS

#include "ofConstants.h"

#ifdef OF_USING_POCO

	#ifndef OF_EVENTS_ADDON
		#include "ofEventUtils.h"

		//-----------------------------------------------
		// event arguments, this are used in oF to pass
		// the data when notifying events

		class ofEventArgs{};

		class ofKeyEventArgs : public ofEventArgs {
		  public:
			int key;
		};

		class ofMouseEventArgs : public ofEventArgs {
		  public:
			int x;
			int y;
			int button;
		};

		class ofTouchEventArgs : public ofEventArgs {
		  public:
			int x;
			int y;
			int id;
		};

		class ofAudioEventArgs : public ofEventArgs {
		  public:
			float* buffer;
			int bufferSize;
			int nChannels;
		};

		class ofResizeEventArgs : public ofEventArgs {
		  public:
			int width;
			int height;
		};
	#else
		#include "ofxEventUtils.h"
	#endif

	class ofCoreEvents {
	  public:
		ofEvent<ofEventArgs> 		setup;
		ofEvent<ofEventArgs> 		update;
		ofEvent<ofEventArgs> 		draw;
		ofEvent<ofEventArgs> 		exit;
		ofEvent<ofResizeEventArgs> 	windowResized;

		ofEvent<ofKeyEventArgs> 	keyPressed;
		ofEvent<ofKeyEventArgs> 	keyReleased;

		ofEvent<ofMouseEventArgs> 	mouseMoved;
		ofEvent<ofMouseEventArgs> 	mouseDragged;
		ofEvent<ofMouseEventArgs> 	mousePressed;
		ofEvent<ofMouseEventArgs> 	mouseReleased;

		ofEvent<ofAudioEventArgs> 	audioReceived;
		ofEvent<ofAudioEventArgs> 	audioRequested;

		ofEvent<ofTouchEventArgs>	touchDown;
		ofEvent<ofTouchEventArgs>	touchUp;
		ofEvent<ofTouchEventArgs>	touchMoved;
		ofEvent<ofTouchEventArgs>	touchDoubleTap;

		void disable(){
			setup.disable();
			draw.disable();
			update.disable();
			exit.disable();
			keyPressed.disable();
			keyReleased.disable();
			mouseDragged.disable();
			mouseReleased.disable();
			mousePressed.disable();
			mouseMoved.disable();
			audioReceived.disable();
			audioRequested.disable();
			touchDown.disable();
			touchUp.disable();
			touchMoved.disable();
			touchDoubleTap.disable();
		}

		void enable(){
			setup.enable();
			draw.enable();
			update.enable();
			exit.enable();
			keyPressed.enable();
			keyReleased.enable();
			mouseDragged.enable();
			mouseReleased.enable();
			mousePressed.enable();
			mouseMoved.enable();
			audioReceived.enable();
			audioRequested.enable();
			touchDown.enable();
			touchUp.enable();
			touchMoved.enable();
			touchDoubleTap.enable();
		}
	};



	extern ofCoreEvents ofEvents;


	class ofTouchListener{
	public:
		ofTouchListener(){}
		virtual ~ofTouchListener(){}

		void registerTouchEvents(){
			ofAddListener(ofEvents.touchDown,this,&ofTouchListener::touchDown);
			ofAddListener(ofEvents.touchUp,this,&ofTouchListener::touchUp);
			ofAddListener(ofEvents.touchMoved,this,&ofTouchListener::touchMoved);
			ofAddListener(ofEvents.touchDoubleTap,this,&ofTouchListener::touchDoubleTap);
		}

		void unregisterTouchEvents(){
			ofRemoveListener(ofEvents.touchDown,this,&ofTouchListener::touchDown);
			ofRemoveListener(ofEvents.touchUp,this,&ofTouchListener::touchUp);
			ofRemoveListener(ofEvents.touchMoved,this,&ofTouchListener::touchMoved);
			ofRemoveListener(ofEvents.touchDoubleTap,this,&ofTouchListener::touchDoubleTap);
		}

		virtual void touchDown(float x, float y, int touchId){}
		virtual void touchMoved(float x, float y, int touchId){}
		virtual void touchUp(float x, float y, int touchId){}
		virtual void touchDoubleTap(float x, float y, int touchId){}

		virtual void touchDown(ofTouchEventArgs & touch){
			touchDown(touch.x, touch.y, touch.id);
		}

		virtual void touchMoved(ofTouchEventArgs & touch){
			touchMoved(touch.x, touch.y, touch.id);
		}

		virtual void touchUp(ofTouchEventArgs & touch){
			touchUp(touch.x,touch.y,touch.id);
		}

		void touchDoubleTap(ofTouchEventArgs & touch){
			touchDoubleTap(touch.x,touch.y,touch.id);
		}
	};


	#endif

#endif

