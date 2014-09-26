
#ifndef COMPUTER_H_
#define COMPUTER_H_ 



class Computer
{
    public:

        Computer();
        Computer(const string &name,
                int cost,
                int weight);
        
        virtual void set(const string &name,

                int cost,
                int weight);
        virtual int price();

        void printmsg();

    protected:
        string name_;
        int cost_;
        int weight_;
};

#endif  /*COMPUTER_H_*/
