#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackgroundHex(0x00000);
    ofSetLogLevel(OF_LOG_NOTICE);
    
    box2d.init();
    box2d.setGravity(0, 20);
    box2d.setFPS(30.0);
    
    // box2d.registerGrabbing();
    box2d.createBounds();
    
    particles.setup(box2d.getWorld());
    
    for (int i = 0; i < particleCount; i++) {
        ofVec2f position = ofVec2f(ofRandom(ofGetWidth()),
                                   ofGetHeight() - ofRandom(300));
        ofVec2f velocity = ofVec2f(0, 0);
        particles.createParticle(position, velocity);
    }
    
    
    gui.setup( "Parameters", "settings.xml" );
    gui.add( hue.setup( "hue", 170, 0, 255 ) );
    gui.add( saturation.setup( "saturation", 255, 0, 255 ) );
    gui.add( brightness.setup( "brightness", 1, 0, 20 ) );
    
    client.setup("127.0.0.1", 7890);
}

//--------------------------------------------------------------
void ofApp::update(){
    box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    float wBox = ofGetWidth() / LEDS;
    
    for(int i=0; i<circles.size(); i++) {
        ofFill();
        ofSetHexColor(0xf6c738);
        circles[i].get()->draw();
    }
    
    for(int i=0; i<boxes.size(); i++) {
        ofFill();
        ofSetHexColor(0xBF2545);
        boxes[i].get()->draw();
    }
    
    particles.draw();
    
    vector<float> f = particles.getXPositions(LEDS);
    vector<ofColor> strip;
    // string text = "LEDs: ";
    for (int i=0; i<LEDS; i++) {
        // ofLog(OF_LOG_NOTICE, "Value"+ofToString(f[i]));
        // *f[i]
        ofColor c = ofColor::fromHsb(hue,saturation,255*f[i]*brightness);
        ofSetColor(c);
        strip.push_back(c);
        ofDrawRectangle(i*wBox+i, 100, wBox, 100);
        // text += ofToString(f[i]) + ", ";
    }
    // ofLog(OF_LOG_NOTICE, text);
    if (!client.isConnected())
    {
        client.tryConnecting();
    }
    else
    {
        client.writeChannelOne(strip);
    }

    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'j') {
        for (int i = 0; i < particleCount; i++) {
            particles.applyForce(i, 2, 0);
        }
    }
    if (key == 'k') {
        for (int i = 0; i < particleCount; i++) {
            particles.applyForce(i, -2, 0);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
