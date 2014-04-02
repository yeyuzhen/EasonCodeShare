SELECT * FROM pta_Out_TelegramInfo;
DELETE FROM pta_Out_TelegramInfo;
SELECT * FROM pta_in_telegraminfo;

INSERT INTO pta_DepartmentInfo(name, parent_id)
VALUES ('AA省公安厅', NULL);

INSERT INTO pta_DepartmentInfo(name, parent_id, ip, port)
VALUES ('AA市公安局', 1, '127.0.0.1', '8080');

INSERT INTO pta_DepartmentInfo(name, parent_id, ip, port)
VALUES ('AA市公安局BB分局', 2, '127.0.0.1', '8080');

INSERT INTO pta_DepartmentInfo(name, parent_id, ip, port)
VALUES ('AA市公安局CC分局', 2, '127.0.0.1', '8080');

SELECT * FROM pta_DepartmentInfo;
--DELETE FROM pta_DepartmentInfo;

INSERT INTO pta_ConfigInfo(my_department_name, my_max_telegram_id, my_max_document_id, my_ip, my_port)
VALUES ('AA市公安局', '20131126001','A公密发[2013]0号', '127.0.0.1', '8080');

SELECT * FROM pta_ConfigInfo;