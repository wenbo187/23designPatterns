#include <iostream>
using namespace std;

class ProductionLine
{
public:
    ProductionLine(){}
    virtual ~ProductionLine(){}
    virtual void Product() = 0;
};

class AppleLine: public ProductionLine
{
public:
    AppleLine(){}
    ~AppleLine(){}

  virtual void Product();
};

class BananaLine: public ProductionLine
{
public:
    BananaLine(){}
    ~BananaLine(){}

    virtual void Product();
};

class Pear: public ProductionLine
{
public:
    Pear(){}
    ~Pear(){}

    virtual void Product();
};

void AppleLine::Product()
{
    cout << "product apple!" << endl;
}
void BananaLine::Product()
{
    cout << "product banana!" << endl;
}
void Pear::Product()
{
    cout << "product pear!" << endl;
}

class SimpleFactory
{
public:
    enum TYPE{
        APPLE,
        BANANA,
        PEAR
    };
    static SimpleFactory* GetInstance();
    ProductionLine *CreateProLine(TYPE type);
private:
    SimpleFactory(){}
};

SimpleFactory *SimpleFactory::GetInstance()
{
    static SimpleFactory factory;
    return &factory;
}

ProductionLine *SimpleFactory::CreateProLine(TYPE type)
{
    ProductionLine* proLine;
    switch (type) {
    case APPLE:
        proLine = new AppleLine();
        break;
    case BANANA:
        proLine = new BananaLine();
        break;
    case PEAR:
        proLine = new Pear();
        break;
    }
    return proLine;
}

int main()
{
	SimpleFactory* factory = SimpleFactory::GetInstance();
    ProductionLine* line1 = factory->CreateProLine(SimpleFactory::APPLE);
    ProductionLine* line2 = factory->CreateProLine(SimpleFactory::BANANA);
    ProductionLine* line3 = factory->CreateProLine(SimpleFactory::PEAR);

    if(line1)
        line1->Product();
    if(line2)
        line2->Product();
    if(line3)
        line3->Product();

	return 0;
}
