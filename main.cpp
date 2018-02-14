#include "neuron.h"

int main()
{	
    class_NeuronNetwork obj_NeuronNetwork;
    obj_NeuronNetwork.SizeNeuroNetwork(2, 2);
    vector <float> InputData = {0.1, 0.1};
    vector < vector <float>> Sinaps = { {0.3, 0.5},
                                        {0.5, 0.5} };
    obj_NeuronNetwork.Run(InputData, Sinaps);
    obj_NeuronNetwork.PrintNetwork();
    return 0;
}
