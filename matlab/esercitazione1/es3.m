A1 = [1 2 3 4 5 6;
    5 6 7 8 9 10;
    9 10 11 12 13 14;
    15 16 17 18 19 20];

A = [1:6;
    5:10;
    9:14;
    15:20];

B = A(:,[end:-1:1]);
% : prima dei due punti non c'è nulla ossia non tocco le riga

C=A(:,[2:2:end]);

D=A([1:2:end],:);

E=A([1 4 3],[5 2]);

v=diag(A)

