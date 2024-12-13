#include "..\include\Paralaje.hpp"

Paralaje::Paralaje()
{
    ultimo=-1;
    posicionUltimoObstaculoPasado = -1;
    iniciado=false;
    puntaje=0;
    if(!obstaculoT.loadFromFile("assets/image/tubo.png"))
    {
        std::cout<<"Error al cargar la textura"<<std::endl;
    }
    if(!baseT.loadFromFile("assets/image/base.png"))
    {
        std::cout<<"Error al cargar la textura"<<std::endl;
    }

    srand(time(NULL));

    obstaculos.push_back(Obstaculo(obstaculoT,500,100+rand()%250));
    obstaculos.push_back(Obstaculo(obstaculoT,850,100+rand()%250));

    sf::Sprite nSprite;

    nSprite.setTexture(baseT);
    nSprite.setPosition(0,700-112);
    nSprite.setScale(1.5f,1.5f);
    bases.push_back(nSprite);
    nSprite.setPosition(336*1.5f,700-112);
    bases.push_back(nSprite);
}

void Paralaje::Actualizar()
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
    int ultimo=(int)obstaculos.size()-1;
    for(int i=0; i<(int)obstaculos.size(); i++)
{
    if(obstaculos[i].GetPosicion().x < 100 && obstaculos[i].GetPosicion().x > posicionUltimoObstaculoPasado)
    {
        puntaje += 10;
        posicionUltimoObstaculoPasado = obstaculos[i].GetPosicion().x;
    }
    if(obstaculos[i].GetPosicion().x <= -100)
    {
        obstaculos.erase(obstaculos.begin()+i);
        i--; // Ajustar el índice después de borrar
        obstaculos.push_back(Obstaculo(obstaculoT, obstaculos[ultimo].GetPosicion().x+350, 100+rand()%250));
        if(i < ultimo) ultimo--;
    }
}
        for(int i=0;i<(int)obstaculos.size();i++)
        {
            obstaculos[i].Actualizar();
        }
}

bool Paralaje::Colision(sf::IntRect rect)
{
    for(int i=0;i<(int)obstaculos.size();i++)
    {
        if(obstaculos[i].Colision(rect)) return true;
    }
    return false;
}

int Paralaje::Puntaje()
{
    return puntaje;
}

void Paralaje::Iniciado()
{
    iniciado=true;
}

void Paralaje::draw(sf::RenderTarget &rt, sf::RenderStates rs) const{
	for(int i = 0; i < (int)obstaculos.size(); i++) rt.draw(obstaculos[i],rs);
	for(int i = 0; i < (int)bases.size(); i++) rt.draw(bases[i],rs);
}