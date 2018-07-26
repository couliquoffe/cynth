/* Local libraries: */
#include "inc/cynth.hpp"

/* Standard libraries: */
#include <iostream>
#include <exception>

using namespace std;

int main() {

    /* -- WASAPI testing: --------------------------------------------------- */

    try {
        CYNTH_API audio_API;

        /* Rendering devices setup: */
        vector<string> device_names;
        device_names = audio_API.getRenderingDevicesNames();
        cout << "Choose output devices from:" << endl;
        for(int i = 0; i < device_names.size(); i++) {
            cout << '\t' << i << ": " << device_names[i] << endl;
        }
        cout << endl;
        cout << "Number of channels: ";
        int input;
        std::vector<int> devices_selected;
        cin >> input;
        switch(input) {
        case 0:
            cout << "Choose 1 or more devices.";
            break;
        case 1:
            cout << "Device: ";
            cin >> input;
            devices_selected.push_back(input);
            break;
        case 2:
            cout << "Left: ";
            cin >> input;
            devices_selected.push_back(input);
            cout << endl;
            cout << "Right: ";
            cin >> input;
            devices_selected.push_back(input);
        default:
            cout << "Surround is not supported yet." << endl;
        }
        
    } catch(exception&) {
        return EXIT_FAILURE;
    }

    /* -- Cynth testing: ---------------------------------------------------- */

    /* Sound Card: */
    // Initiate:
    Cynth::SoundCard sound_card;
    // TODO: Setup API: Connect with the physical sound card etc.

    /* Tone Generator: */
    Cynth::ToneGeneratorDevice tone_generator1(Cynth::SINE);
    Cynth::ToneGeneratorDevice tone_generator2(Cynth::SQUARE);
    Cynth::ToneGeneratorDevice tone_generator3(Cynth::SAW);
    Cynth::ToneGeneratorDevice tone_generator4(Cynth::TRIANGLE);
    
    /*cout << "Sine Wave:" << endl;
    tone_generator1.draw();
    cout << endl;
    cout << "Square Wave:" << endl;
    tone_generator2.draw();
    cout << endl;
    cout << "Saw Wave:" << endl;
    tone_generator3.draw();
    cout << endl;
    cout << "Triangle Wave:" << endl;
    tone_generator4.draw();
    cout << endl;*/

    return 0;
}