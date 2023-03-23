#include <iostream>
#include "Service1.h"
#include "Repository1.h"
#include "Repository4.h"
#include "Eveniment.h"
#include "Service4.h"
#include "Repository2.h"
#include "Retea.h"
#include "Ui.h"

int main()
{
    Repository1 repo{};
    repo.AddElement(Utilizator(1, "Chis Madalina"));
    repo.AddElement(Utilizator(2, "Vlad Popescu"));
    repo.AddElement(Utilizator(3, "Mihai Gheorghe"));
    repo.AddElement(Utilizator(4, "Cristian Manea"));
    repo.AddElement(Utilizator(5, "Madalina Carmen"));
    repo.AddElement(Utilizator(6, "Irina Fodor"));
    repo.AddElement(Utilizator(7, "Denisa Popa"));
    repo.AddElement(Utilizator(8, "Ioana Dumitrescu"));
    repo.AddElement(Utilizator(9, "Avram Tudor"));
    repo.AddElement(Utilizator(10, "Achim Maria"));
    repo.AddElement(Utilizator(11, "Badu Mihai"));
    repo.AddElement(Utilizator(12, "Bucur Bianca"));
    repo.AddElement(Utilizator(13, "Copindean Adelina"));
    repo.AddElement(Utilizator(14, "Maier Ovidiu"));
    repo.AddElement(Utilizator(15, "Chis Tudor"));
    Repository2 friendshipRepo{};
    friendshipRepo.AddElement(Prietenie(Utilizator(1, "Chis Madalina"), Utilizator(2, "Vlad Popescu")));
    friendshipRepo.AddElement(Prietenie(Utilizator(1, "Chis Madalina"), Utilizator(3, "Mihai Gheorghe")));
    friendshipRepo.AddElement(Prietenie(Utilizator(4, "Cristian Manea"), Utilizator(2, "Vlad Popescu")));
    friendshipRepo.AddElement(Prietenie(Utilizator(2, "Vlad Popescu"), Utilizator(15, "Chis Tudor")));
    friendshipRepo.AddElement(Prietenie(Utilizator(3, "Mihai Gheorghe"), Utilizator(9, "Avram Tudor")));
    friendshipRepo.AddElement(Prietenie(Utilizator(9, "Avram Tudor"), Utilizator(15, "Chis Tudor")));
    friendshipRepo.AddElement(Prietenie(Utilizator(4, "Cristian Manea"), Utilizator(7, "Denisa Popa")));
    friendshipRepo.AddElement(Prietenie(Utilizator(12, "Bucur Bianca"), Utilizator(13, "Copindean Adelina")));
    friendshipRepo.AddElement(Prietenie(Utilizator(14, "Maier Ovidiu"), Utilizator(11, "Badu Mihai")));
    friendshipRepo.AddElement(Prietenie(Utilizator(13, "Copindean Adelina"), Utilizator(5, "Madalina Carmen")));
    friendshipRepo.AddElement(Prietenie(Utilizator(8, "Ioana Dumitrescu"), Utilizator(6, "Irina Fodor")));
    friendshipRepo.AddElement(Prietenie(Utilizator(12, "Bucur Bianca"), Utilizator(5, "Madalina Carmen")));
    friendshipRepo.AddElement(Prietenie(Utilizator(6, "Irina Fodor"), Utilizator(10, "Achim Maria")));
    friendshipRepo.AddElement(Prietenie(Utilizator(8, "Ioana Dumitrescu"), Utilizator(10, "Achim Maria")));
    friendshipRepo.AddElement(Prietenie(Utilizator(11, "Badu Mihai"), Utilizator(7, "Denisa Popa")));
    friendshipRepo.AddElement(Prietenie(Utilizator(14, "Maier Ovidiu"), Utilizator(4, "Cristian Manea")));
    Retea r{ repo, friendshipRepo };
    Eveniment e("firstEvent", DataC(26, 7, 2022), "Locatie supriza", "test");
    Eveniment e2("secondEvent", DataC(11, 8, 2022), "Locatie necunoscuta", "test");
    Repository4 eventRepo{};
    eventRepo.AddInterestedPerson(e, Utilizator(1, "Chis Madalina"));
    eventRepo.AddInterestedPerson(e, Utilizator(3, "Mihai Gheorghe"));
    eventRepo.AddInterestedPerson(e2, Utilizator(3, "Mihai Gheorghe"));
    eventRepo.AddInterestedPerson(e2, Utilizator(2, "Vlad Popescu"));
    std::vector<Eveniment> eArray;
    eArray.push_back(e);
    eArray.push_back(e2);
    Service4 eventController(eventRepo, eArray);
    Repository3 messageRepo{};
    messageRepo.AddElement(Mesaj(Utilizator(1, "Chis Madalina"), Utilizator(3, "Mihai Gheorghe"), "Salut!"));
    messageRepo.AddElement(Mesaj(Utilizator(2, "Vlad Popescu"), Utilizator(1, "Chis Madalina"), "Ce faci?"));
    messageRepo.AddElement(Mesaj(Utilizator(3, "Mihai Gheorghe"), Utilizator(1, "Chis Madalina"), "Bunaa!"));
    messageRepo.AddElement(Mesaj(Utilizator(1, "Chis Madalina"), Utilizator(2, "Vlad Popescu"), "Sunt bine, tu?"));
    messageRepo.AddElement(Mesaj(Utilizator(4, "Cristian Manea"), Utilizator(2, "Vlad Popescu"), "Ne vedem?"));
    messageRepo.AddElement(Mesaj(Utilizator(2, "Vlad Popescu"), Utilizator(4, "Cristian Manea"), "Sigur"));
    messageRepo.AddElement(Mesaj(Utilizator(2, "Vlad Popescu"), Utilizator(15, "Chis Tudor"), "Te astept!"));
    messageRepo.AddElement(Mesaj(Utilizator(15, "Chis Tudor"), Utilizator(2, "Vlad popescu"), "Sosesc acum"));
    messageRepo.AddElement(Mesaj(Utilizator(3, "Mihai Gheorghe"), Utilizator(9, "Avram Tudor"), "Sunt la Cinema"));
    messageRepo.AddElement(Mesaj(Utilizator(9, "Avram Tudor"), Utilizator(3, "Mihai Gheorghe"), "Vin si eu"));
    messageRepo.AddElement(Mesaj(Utilizator(9, "Avram Tudor"), Utilizator(15, "Chis Tudor"), "Vii la KFC?"));
    messageRepo.AddElement(Mesaj(Utilizator(15, "Chis Tudor"), Utilizator(9, "Avram Tudor"), "Desigur"));
    messageRepo.AddElement(Mesaj(Utilizator(4, "Cristian Manea"), Utilizator(7, "Denisa Popa"), "Hei"));
    messageRepo.AddElement(Mesaj(Utilizator(7, "Denisa Popa"), Utilizator(4, "Cristian Manea"), "Salut!"));
    messageRepo.AddElement(Mesaj(Utilizator(12, "Bucur Bianca"), Utilizator(13, "Copindean Adelina"), "Multmesc!"));
    messageRepo.AddElement(Mesaj(Utilizator(13, "Copindean Adelina"), Utilizator(12, "Bucur Bianca"), "La multi ani!"));
    messageRepo.AddElement(Mesaj(Utilizator(14, "Maier Ovidiu"), Utilizator(11, "Badu Mihai"), "Buna ziua!"));
    messageRepo.AddElement(Mesaj(Utilizator(11, "Badu Mihai"), Utilizator(14, "Maier Ovidiu"), "Buna Ziua!"));
    messageRepo.AddElement(Mesaj(Utilizator(13, "Copindean Adelina"), Utilizator(5, "Madalina Carmen"), "Buna, Mada!"));
    messageRepo.AddElement(Mesaj(Utilizator(5, "Madalina Carmen"), Utilizator(13, "Copindean Adelina"), "Hei, Ade!"));
    messageRepo.AddElement(Mesaj(Utilizator(8, "Ioana Dumitrescu"), Utilizator(6, "Irina Fodor"), "Ramane stabilit?"));
    messageRepo.AddElement(Mesaj(Utilizator(6, "Irina Fodor"), Utilizator(8, "Ioana Dumitrescu"), "Exact cum am stabilit"));
    messageRepo.AddElement(Mesaj(Utilizator(12, "Bucur Bianca"), Utilizator(5, "Madalina Chis"), "Vii la ziua mea?"));
    messageRepo.AddElement(Mesaj(Utilizator(5, "Madalina Chis"), Utilizator(12, "Bucur Bianca"), "Da"));
    messageRepo.AddElement(Mesaj(Utilizator(6, "Irina Fodor"), Utilizator(10, "Achim Maria"), "Sunt trista!"));
    messageRepo.AddElement(Mesaj(Utilizator(10, "Achim Maria"), Utilizator(6, "Irina Fodor"), "De ce?"));
    messageRepo.AddElement(Mesaj(Utilizator(8, "Ioana Dumitrescu"), Utilizator(10, "Achim Maria"), "Sunt la scoala"));
    messageRepo.AddElement(Mesaj(Utilizator(10, "Achim Maria"), Utilizator(8, "Ioana Dumitrescu"), "Succes!"));
    messageRepo.AddElement(Mesaj(Utilizator(11, "Badu Mihai"), Utilizator(7, "Denisa Popa"), "Am luat 10!"));
    messageRepo.AddElement(Mesaj(Utilizator(7, "Denisa Popa"), Utilizator(11, "Badu Mihai"), "Bravo!"));
    messageRepo.AddElement(Mesaj(Utilizator(14, "Maier Ovidiu"), Utilizator(4, "Cristian Manea"), "Super gol!"));
    messageRepo.AddElement(Mesaj(Utilizator(4, "Cristian Manea"), Utilizator(14, "Maier Ovidiu"), "Stiu"));
    Service3 messageManager(messageRepo);
    Ui ui{ r, eventController, messageManager };
    ui.mainMenu();
}