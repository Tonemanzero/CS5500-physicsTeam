#ifndef object_h
#define object_h
#include <string>
#include <vector>

//the base object
//once set, cannot be changed
class templateObject
{
public:
    templateObject(std::string,int,int,int,int,bool,bool);
    std::string getName();
    int getId();
    int getHp();
    int getStrength();
    int getWeight();
    bool getIsFlamable();
    bool getIsWetable();
    
private:
    int id, baseHp, strength, weight;
    bool isFlamable, isWetable;
    std::string name;
};
class templateObjectList
{
public:
    templateObjectList();
    int addTemplate(templateObject);
    int addTemplate(std::string,int,int,int,bool,bool);
    templateObject getTemplate(int);
    int findTemplate(std::string);
    int getSize();
private:
    std::vector<templateObject> list;
    int size;
};
//object used in world
//modifiable
//id refers to template location in the template list
class object
{
public:
    object();
    object(int,int,int,int,bool,bool);
    object(templateObject);
    object(templateObjectList,int);
    int getId();
    int getHp();
    int getStrength();
    int getWeight();
    bool getStateFire();
    bool getStateWet();
   
    void setHp(int);
    void setStrength(int);
    void setWeight(int);
    void setStateFire(bool);
    void setStateWet(bool);

private:
    int id,hp,strength,weight;
    bool stateFire, stateWet;
};





#endif