#include "llcd.hpp"
uint32_t Rbase = 134;
uint8_t randon(){
    uint32_t x = Rbase;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
    Rbase = x;
    return x;
}

uint8_t r(uint16_t v){
    return (randon()%v)+1;
}

int16_t map[312];//13(h)x24(w)
//starts at 7x12
uint16_t p(uint8_t x,uint8_t y){
    return x+(y*24);
}
uint16_t head = p(12,7);
uint16_t next = p(12,7);
int16_t in = 0;
uint16_t l = 1;
uint16_t fruit = 0;
bool end = false;
#define m_no 0
#define m_up 1
#define m_down 2
#define m_left 3
#define m_right 4
uint8_t move = m_no;
void newFruid(){
    uint16_t pp;
    while (true)
    {
        pp=r(312)-1;
        if(map[pp]==-1&&pp!=head){
            fruit=pp;
            break;
        }

    }
    
    
}
uint8_t tickl = 0;
bool tick(){
    if(tickl==0){
        tickl++;
        return true;
    }else{
        tickl++;
        if(tickl>2){
            tickl=0;
        }
        return false;
    }
}
void reset(){
    
    move = m_up;
    map[p(12,7)]=p(13,7);
    head = p(12,7);
    for(int16_t i = 0;i<312;i++){
        map[i] = -1;
    }
    newFruid();
    in = 25;
    end = false;
}
int main(){
    lcd_h;//26(27) - 13
    lcd_w;//48 - 24
    // 130-135 not use
    reset();
    llcd::llcd([](llcd::ctx& c,llcd::buttons& b,llcd::audio& a){
        if(b.isAPressed()||b.isBPressed()){
            //reset
            reset();
        }
        if(end)return;
        if(b.isUpPressed()&&move!=m_down)move=m_up;    
        if(b.isDownPressed()&&move!=m_up)move=m_down;    
        if(b.isLeftPressed()&&move!=m_right)move=m_left;    
        if(b.isRightPressed()&&move!=m_left)move=m_right;
        
        
        if(tick()){
            switch (move)
            {
            case m_up:
                if(head<=23){
                    next = head+(24*12);
                }else{
                    next = head-24;
                }
                break;
                case m_down:
                if(head+24>=312){
                    next = head-(24*12);
                }else{
                    next = head+24;
                }
                break;
                case m_left:
                if(head%24==0){
                    next=head+23;
                }else{
                    next = head-1;
                }
                break;
                case m_right:
                if(head%24==23){
                    next = head+1-24;
                }else{
                    next = head+1;
                }
                break;
            }
            in = map[head];
            if(map[next]!=-1&&head!=next)end=true;
            if(next==fruit){
                newFruid();
            }else{
                
                    for(int16_t il = 0;il<312;il++){
                        if(in==-1){
                            break;
                        }else if(map[in]!=-1&&map[map[in]]==-1){
                            map[in]=-1;
                            break;
                        }else{
                            in = map[in];
                        }
                    }
                
                
            }
            
            map[next]=head;
            head = next;
            
            c.fill(c_black);
            for(uint16_t ix = 0;ix<24;ix++){
                for(uint16_t iy = 0;iy<13;iy++){
                    if(ix+(iy*24)==fruit){
                            c.fillRect((ix*10),(iy*10),10,10,llcd::RGB(255,0,0));
                    }else if(map[ix+(iy*24)]!=-1||ix+(iy*24)==head){
                            c.fillRect((ix*10)+1,(iy*10)+1,8,8,llcd::RGB(0,255,00));
                    }else{
                        
                    }
                }
            }
            //c.drawTriangle(10,10,20,10,35,40,llcd::RGB(0,0,255));
            
        }
        
        
    });
}