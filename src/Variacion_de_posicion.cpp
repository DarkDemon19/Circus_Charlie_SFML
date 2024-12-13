#include "..\include\Variacion_de_posicion.hpp"

Variacion_de_posicion::Variacion_de_posicion()
{
    ultimo=-1;
    posicionUltimoChoquesPasado = -1;
    iniciado=false;
    puntaje=0;
    if(!choquesT.loadFromFile("assets/image/tubo.png"))
    {
        std::cout<<"Error al cargar la textura"<<std::endl;
    }
    if(!baseT.loadFromFile("assets/image/base.png"))
    {
        std::cout<<"Error al cargar la textura"<<std::endl;
    }

    srand(time(NULL));

    choques.push_back(Choques(choquesT,500,100+rand()%250));
    choques.push_back(Choques(choquesT,850,100+rand()%250));

    sf::Sprite nSprite;

    nSprite.setTexture(baseT);
    nSprite.setPosition(0,700-112);
    nSprite.setScale(1.5f,1.5f);
    bases.push_back(nSprite);
    nSprite.setPosition(336*1.5f,700-112);
    bases.push_back(nSprite);
}

void Variacion_de_posicion::Actualizar()
{
    for(int i=0;i<(int)bases.size();i++)
    {
        if(bases[i].getPosition().x<-(336*1.5f))
        {
            sf::Sprite nSprite=bases[(int)bases.size()-1];
            nSprite.setPosition(nSprite.getPosition().x+336*1.5f,700-112);
            bases.push_back(nSprite);
            bases.erase(bases.begin()+i);
            continue;
        }
    }
    for(int i=0;i<(int)bases.size();i++)
    {
        bases[i].move(-2.5f,0);
    }
    if(!iniciado) return;
    int ultimo=(int)choques.size()-1;
    for(int i=0; i<(int)choques.size(); i++)
{
    if(choques[i].GetPosicion().x < 100 && choques[i].GetPosicion().x > posicionUltimoChoquesPasado)
    {
        puntaje += 10;
        posicionUltimoChoquesPasado = choques[i].GetPosicion().x;
    }
    if(choques[i].GetPosicion().x <= -100)
    {
        choques.erase(choques.begin()+i);
        i--; // Ajustar el índice después de borrar
        choques.push_back(Choques(choquesT, choques[ultimo].GetPosicion().x+350, 100+rand()%250));
        if(i < ultimo) ultimo--;
    }
}
        for(int i=0;i<(int)choques.size();i++)
        {
            choques[i].Actualizar();
        }
}

bool Variacion_de_posicion::Colision(sf::IntRect rect)
{
    for(int i=0;i<(int)choques.size();i++)
    {
        if(choques[i].Colision(rect)) return true;
    }
    return false;
}

int Variacion_de_posicion::Puntaje()
{
    return puntaje;
}

void Variacion_de_posicion::Iniciado()
{
    iniciado=true;
}

void Variacion_de_posicion::draw(sf::RenderTarget &rt, sf::RenderStates rs) const{
	for(int i = 0; i < (int)choques.size(); i++) rt.draw(choques[i],rs);
	for(int i = 0; i < (int)bases.size(); i++) rt.draw(bases[i],rs);
}