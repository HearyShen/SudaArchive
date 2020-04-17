function Bezier3by3(X,Y,Z)

M = [
-1 3 -3 1
3 -6 3 0
-3 3 0 0
1 0 0 0
];

B(:,:,1) = X;
B(:,:,2) = Y;
B(:,:,3) = Z;
for i = 1:3
    Q(:,:,i) = M*B(:,:,i)*M';
    for u = 0:10
        for v = 0:10
            u3 = (u/10)^3; u2 = (u/10)^2; u1 = u/10;
            v3 = (v/10)^3; v2 = (v/10)^2; v1 = v/10;
            S(u+1,v+1,i) = [u3 u2 u1 1] * Q(:,:,i) * [v3 v2 v1 1]';
        end
    end
end
surf(S(:,:,1),S(:,:,2),S(:,:,3))

end
