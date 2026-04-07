DROP DATABASE IF EXISTS company_functions;
CREATE DATABASE company_functions;
USE company_functions;

CREATE TABLE employees (
    employee_id INT AUTO_INCREMENT PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    department VARCHAR(50),
    salary DECIMAL(10,2),
    hire_date DATE
);

CREATE TABLE projects (
    project_id INT AUTO_INCREMENT PRIMARY KEY,
    project_name VARCHAR(100),
    budget DECIMAL(12,2),
    start_date DATE,
    end_date DATE
);

CREATE TABLE project_assignments (
    assignment_id INT AUTO_INCREMENT PRIMARY KEY,
    employee_id INT,
    project_id INT,
    hours_worked INT,
    FOREIGN KEY (employee_id) REFERENCES employees(employee_id),
    FOREIGN KEY (project_id) REFERENCES projects(project_id)
);

INSERT INTO employees (first_name, last_name, department, salary, hire_date) VALUES
('Alejandro', 'García', 'IT', 45000.00, '2022-03-15'),
('Marta', 'Rodríguez', 'Marketing', 38000.50, '2021-06-10'),
('Lucía', 'Fernández', 'RRHH', 32000.00, '2023-01-20'),
('Javier', 'López', 'IT', 42000.00, '2022-11-02'),
('Sofía', 'Martínez', 'Ventas', 35500.00, '2020-09-12');

INSERT INTO projects (project_name, budget, start_date, end_date) VALUES
('Migración a la Nube', 150000.00, '2024-01-10', '2024-12-20'),
('Campaña Verano 2025', 50000.00, '2025-03-01', '2025-08-31'),
('Renovación de Portal Empleado', 25000.00, '2026-02-15', null);

INSERT INTO project_assignments (employee_id, project_id, hours_worked) VALUES
(1, 1, 120),
(4, 1, 100),
(2, 2, 80),
(5, 2, 45),
(3, 3, 60),
(1, 3, 20);


/*
? Respuesta de ejercicio
*/


DROP DATABASE shop_trigger;
CREATE DATABASE shop_trigger;
USE shop_trigger;

Create table products (
    product_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    stock INT NOT NULL,
    price DECIMAL(10,2) NOT NULL,
    discount DECIMAL(5,2) DEFAULT 0.00,
    special_sale BOOLEAN
);
Create table orders (
    order_id INT AUTO_INCREMENT PRIMARY KEY,
    order_date DATE, 
    status VARCHAR(50) NOT NULL,
    total DECIMAL(10,2) NOT NULL
);
Create table order_products (
    order_id INT,
    product_id INT,
    quantity INT NOT NULL,
    unit_price DECIMAL(10,2) NOT NULL,
    primary key (order_id, product_id),
    foreign key (order_id) references orders(order_id),
    foreign key (product_id) references products(product_id)
);
Create table audit (
    audit_id INT AUTO_INCREMENT PRIMARY KEY,
    action VARCHAR(100) NOT NULL,
    date DATETIME NOT NULL,
    description TEXT
);

INSERT INTO products (name, stock, price, discount, special_sale)
VALUES
('Laptop', 10, 1000, 10, TRUE),
('Mouse', 50, 20, 0, FALSE),
('Keyboard', 30, 50, 5, TRUE),
('Monitor', 20, 200, 15, FALSE);
INSERT INTO orders (status, total) 
VALUES
('CREATED', 0.00);


/* 
* Fecha automática en la tabla ORDERS 
* Create a trigger to automatically set the order date when inserting a new order.
* Creame un trigger que detecte cuando se inserta un nuevo pedido(order) en mi tabla
* y me inserte también la fecha del pedido.

*/

CREATE TRIGGER trg_set_order_date
BEFORE INSERT ON orders
FOR EACH ROW
BEGIN
    SET NEW.order_date = CURDATE();
END;

/* 
* Fecha automática en la tabla ORDERS 
* Create a trigger to update product stock after each order.
* Crear un trigger que actualice le stock despues en cada orden
*/

/*
crear una variable que se "stock actual"
consultar el stock acutal del producto con un select
guardarlo en mi variable "stock actual"
comparar si mi vaiable "stock actual" es menor a la cantidad que qiero comprar
no se puede comprar porque no hay stock suficiente
Si mi variable si es mayor o igual a la cantidad que quiero comprar, entonces se puede comprar 
y se actualiza el stock restando la cantidad que se compro
*/
CREATE TRIGGER trg_validate_stock
BEFORE INSERT ON order_products
FOR EACH ROW
BEGIN
    DECLARE current_stock INT;

    SELECT stock INTO current_stock 
    FROM products 
    WHERE product_id = NEW.product_id;

    IF current_stock < NEW.quantity THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'No hay stock suficiente para este producto.';
    ELSE
        UPDATE products

        SET stock = current_stock - NEW.quantity
        WHERE product_id = NEW.product_id;
    END IF;
END;

/*
* Create an audit trigger to log every new order.
* Crear un trigger de auditoría que registre cada orden insertada
*/
CREATE TRIGGER trg_audit_new_order
AFTER INSERT ON orders
FOR EACH ROW
BEGIN
    INSERT INTO audit (action, date, description)
    VALUES ('NUEVA ORDER', NEW.order_date, CONCAT("Se ha creado una nueva order con ID: ", NEW.order_id));
END;
