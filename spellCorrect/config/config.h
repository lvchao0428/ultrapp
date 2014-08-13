#ifndef CONFIG_H_
#define CONFIG_H_ 

#include <string>
#include <vector>


class config
{
    public:
        config();
        void read_config(const string &name);
        
    private:
        std::string config_name_;
        


};

#endif  /*CONFIG_H_*/
