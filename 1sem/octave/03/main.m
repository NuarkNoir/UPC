# ����� 1
# ����� ��������
V = 33
# ������������� ���� ������� ��������
rand('state', V)

# ����� 2
# ������ ����� 1..100
v1 = 1:100
v2 = randi([0, 1], [1, 100])
# ��������� ������� v1 � v2
v3 = v1 + v2
v3 = v3 .* ~mod(v3, 2)

# ����� 3
# ������ ������ �� 99*V ��������� �������� �� 0..3
r = rand([1, 99*V]) .* 3;
t = 0:0.01:3;
# �������, ��������� ���-�� ��������� r < t
f = @(x) length(r(r < x));
figure;
plot(t, arrayfun(f, t));
print("3.png")

# ����� 4
# ������ 4 ������� ����� � ����� ���������
figure;
plot(rand([V+12, 4]), rand([V+12, 4]));
print("4.png")
# ����� 5
# ������ 4 ������� ����� � ����� ������������
figure;
plot3(rand([V+12, 4]), rand([V+12, 4]), rand([V+12, 4]));
print("5.png")
# ����� 6
# ������ ������� � 3 + V ������
t = 0:pi/20:2*pi*(3+V);
r = t .^ 2;
x = r .* cos(t);
y = r .* sin(t);
figure;
plot(x, y);
print("6.png")
# ����� 7
# ��������� � ������������ ������ ������� z=cos(0.5Vx)x3+y2 �
# ���� ������������� ����� � � ���� ����������� ����������� �
# ������� �� -4 �� 4 �� ������ ���������� � ����� 0,1. �
# ����� ������� ��������� ��� ���������.
X = -4:0.1:4;
Y = -4:0.1:4;
[x, y] = meshgrid(X, Y);
z = (cos(x .* (V*0.5)) .* x.^3) + y.^2;
figure;
mesh(z)
xlabel("x");
ylabel("y");
zlabel("z");
print("7_1.png")
figure;
surf(z)
xlabel("x");
ylabel("y");
zlabel("z");
print("7_2.png")

# ����� 11
nflip = 9*V
nexp = 1001+V
s = flip_stats(nflip, nexp)
result = s / nexp
figure;
bar(result)
print("11.png")