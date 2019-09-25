using namespace std;

//Exercice 1a
void negCounter()
{
    int counter(0);
    int input;
    cout << "Enter a number (enter a letter to stop): ";
    while (cin >> input)
    {
        cout << "Enter a number (enter a letter to stop): ";
        if (input < 0)
        {
            counter++;
        }
    }
    cout << "Negative numbers: " << counter <<endl;
}

//Exercice 1b
void negCounter2()
{
    int counter(0);
    string input;
    vector<string>numbers;

    cout<<"Enter a list of ints seperated by spaces"<<endl;
    getline(cin, input);

    istringstream ss(input);
    do{
        string word;
        ss >> word;
        //cout<<"aa"<<word<<"aa"<<endl;
        numbers.push_back(word);
    } while (ss);

    for(int i = 0; i<numbers.size() - 1;i++){
        if(stoi(numbers[i])<0){
            counter++;
        }
    }
    cout<< "Negative numbers: " << counter <<endl;
}

//Exercice 2
void affiche(int lower, int upper){
    int lineCounter(0);
    if (lower > upper)
    {
        cout<<"Lower number is higher than upper number";
    }
    else
    {
        for (int i = lower; i < upper; i++){
            lineCounter++;
            cout<<i<<", ";
            if (lineCounter == 10){
                cout<<"\n";
                lineCounter = 0;
                }
            
        }
    }
    cout << "\n";
}

//Exercice 3
void racineCarre(){
    int input;
    float racine;
    cout << "Donnez un nombre positif : ";
    while (cin>> input && input != 0)
    {
        if (input < 0)
        {
            cout<<"SVP Positif \n";
        }

        else
        {
            racine = sqrt(static_cast<float>(input));
            cout << "sa racine carrée est : "<<racine<<"\n";
        }

        cout << "Donnez un nombre positif : ";
        }
}