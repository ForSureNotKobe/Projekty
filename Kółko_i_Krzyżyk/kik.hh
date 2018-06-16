#ifndef KIK_HH
#define KIK_HH


class KiK{
  int roz;
  int prog;
  char* plansza;
  bool Wygrana(char gracz, bool echo);
  bool Remis(bool echo);
  int MiniMaxAB(char gracz, int alfa, int beta);
  int Przeciwnik();
  void Plansza();
  void Ruch(char &gracz);
  void NowaPlansza();
public:
  KiK(int rozm, int ile);
  void Gra();
};
#endif
