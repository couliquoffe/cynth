#pragma once

/* Local libraries: */
#include "platform.hpp"
#include "rack/components/transmitter_port.hpp"
#include "user_library/functions/sequence_function.hpp"

namespace Cynth::UserLibrary::Devices {

    /*/ Sequencer Device:

        Used to generate rhythmic patters of frequency values.
    /*/
    class CYNTH_EXPORT Sequencer {
    private:
        /* Aliases: */
        using TransmitterPort = Cynth::Rack::Components::TransmitterPort;
        using SequenceFunction = Cynth::UserLibrary::Functions::SequenceFunction;

        SequenceFunction seq_function;

    public:
        /* Constructor: */
        Sequencer();

        Sequencer& operator<<(SequenceFunction f);

        /* Ports: */
        // TODO: Make private and allow read only.
        TransmitterPort freq_port;
        TransmitterPort amp_port;
        //TriggerTransmitterPort amp_port; // TODO
    };

}