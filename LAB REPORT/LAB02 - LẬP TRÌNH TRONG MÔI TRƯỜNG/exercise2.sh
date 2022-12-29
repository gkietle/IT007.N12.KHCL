#! /bin/sh
while [ true ]; do
    # Cho phép chạy vòng lặp vô hạn
    echo -n "Nhap ten: "
    # In ra màn hình "Nhap ten: " và không xuống dòng
    read ten
    # Nhập vào từ bàn phím cho biến ten
    echo -n "Nhap MSSV: "
    # In ra màn hình "Nhap MSSV: " và không xuống dòng
    read mssv
    # Nhập vào từ bàn phím cho biến mssv
    if [ "$mssv" = "21522255" ]; then
        # Kiểm tra chuỗi ký tự của biến $mssv có bằng chuỗi "21520283" không
        echo "\nMSSV trung khop"
        echo "Ten: $ten\nMSSV: $mssv"
        # In ra màn hình "Ten: $ten\nMSSV: $mssv" với $ten và $mssv lần lượt là giá trị của biến ten và mssv
        break
        # Dừng lại vòng lặp
    else
        # Trường hợp ngược lại của if
        echo "\nMSSV khong trung khop, Nhap lai MSSV va ten!!!"
        # In ra màn hình "Nhap lai MSSV va ten!!!"
    fi
done