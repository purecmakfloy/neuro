#include <iostream>
#include <vector>

using namespace std;

class class_NeuronNetwork{
private:
    struct Neuron{
    float Input;
    float Sinaps;
    float Output;
    Neuron(float a0, float a1, float a2) :
        Input(a0), Sinaps(a1), Output(a2) {};
    };
    vector < vector <Neuron> > Network;
public:
    void SizeNeuroNetwork(int, int);
    void Run(vector <float>, vector <vector <float>>);
    void PrintNetwork(void);
};

void class_NeuronNetwork::SizeNeuroNetwork(int CountLayers, int CountNeurons){
    cout << "Set size NeuroNetwork is [ " << CountLayers << " x " << CountNeurons << " ]" << endl;
    vector <Neuron> VectorPrototipeLayer;
    for (int i = 0; i < CountNeurons; i++)
        VectorPrototipeLayer.push_back( Neuron(0, 0.5, 0) );
    for (int i = 0; i < CountLayers; i++)
        Network.push_back( VectorPrototipeLayer );
}

void class_NeuronNetwork::Run(vector <float> InputData, vector <vector <float>> Sinaps){
    int i = 0, j = 0;
    for (auto _ : Network[0]){
        Network[0][i].Input = InputData[i];
        i++;
    }
    i = 0; j =0;
    for (auto t1 : Network){
        for (auto t2 : t1){
            Network[i][j].Sinaps = Sinaps[i][j];
            j++;
        }
        j = 0;
        i++;
    }
    float sum;
    for (i = 0; i < Network.size(); i++){
        sum = 0;
        for (int j = 0; j < Network[i].size(); j++)
            sum += Network[i][j].Input;
            for (int j = 0; j < Network[i].size(); j++){
                Network[i][j].Output = sum * Network[i][j].Sinaps;
                if (Network[i][j].Output > 1)
		    Network[i][j].Output = 1;
		    if (Network[i][j].Output < -1)
		        Network[i][j].Output = -1;
                        if (i != Network.size() - 1)
                            Network[i + 1][j].Input = Network[i][j].Output;
            }
    }
}

void class_NeuronNetwork::PrintNetwork(void){
    cout << "Input matrix: " << endl;
    for (auto i : Network){
        for (auto j : i)
            cout << j.Input << "\t";
        cout << endl;
    }
    cout << "Sinaps matrix: " << endl;
    for (auto i : Network){
        for (auto j : i)
            cout << j.Sinaps << "\t";
        cout << endl;
    }
    cout << "Output matrix: " << endl;
    for (auto i : Network){
        for (auto j : i)
            cout << j.Output << "\t";
        cout << endl;
    }
}
