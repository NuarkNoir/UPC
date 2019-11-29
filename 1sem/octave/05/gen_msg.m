% ��������� ��������� ���������� ��������� � ��������, ���������� �� ����� 36 ��������: 0, ..., 9, A, ..., Z.
% �����: ������ ������������ �������.
% ����: 26 ������� 2019 �.
% ������: 0.2
% ���������:
% p - ������, ���������� �� 2 �� 36 ��������������� �����.
%     ����������� �������� ��������.
% len - ����� �����.
%     ����� ���������.
function msg = gen_msg(p, len)
    % ������ ������ �������� �������� 0, ..., 9, A, ..., Z
    alph = ['0':'9' 'A':'Z'];
    % ���� p �� ������, ������
    if ~isvector(p)
        error('p must be a vector')
    end
    % ���� ����� ������� p ������ ����� alph, ������
    if length(p) > length(alph)
        % ������� ��������� �� ������, ���������� � ���� ����� ����� (%d) � ����� ��������
        error('p is too long (%d > %d)', length(p), length(alph));
    end
    % ���� ����� ������� p ������ 2, ������
    if length(p) < 2
        error('p is too short (%d < 2)', length(p));
    end
    % ���� ����� �� ���� �����, ������
    if ~isscalar(len)
        error('len must be a scalar')
    end
    % ���� ����� ������ 1, ������
    if len < 1
        error('len is too small (%d < 1)', len)
    end
    % ������ ������ ������ ��� ������ ���������
    msg = '';
    % ���� �� i �� 1 �� len
    for i = 1:len
        % ������� �������� ��������� � ��������� ������������� ������ � msg
        msg(i) = alph(rand_discr(p));
    end
end

% ������� ��������� ������ ���������� ����� i � ������������ p(i).
% ���������:
% p - ������ ��������������� �����, ����� ��������� �������� ����� 1.
%     �����������.
function r = rand_discr(p)
    r = sum(cumsum(p) < rand()) + 1;
end
