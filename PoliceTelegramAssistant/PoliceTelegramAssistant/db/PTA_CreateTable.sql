-- 已发电报信息表
-- DROP TABLE pta_Out_TelegramInfo;
CREATE TABLE pta_Out_TelegramInfo
(
  id INTEGER PRIMARY KEY,
  telegram_id TEXT,  -- 发电编号
  document_id TEXT,  -- 发电文号
  date_time TEXT,  -- 发电时间
  department_name TEXT,  -- 发电单位
  title TEXT,  -- 文件标题
  urgency_level TEXT,  -- 等级
  secret_level TEXT,  -- 密级
  page_number TEXT,  -- 页数
  operator TEXT,  -- 值机员工号
  send_to_list TEXT,  -- 主送，竖线分割的部门名称串
  copy_to_list TEXT,  -- 抄送，竖线分割的部门名称串
  copy_report_list TEXT  -- 抄报，竖线分割的抄报对象串
);


-- 已收电报信息表
-- DROP TABLE pta_In_TelegramInfo;
CREATE TABLE pta_In_TelegramInfo
(
  id INTEGER PRIMARY KEY,
  telegram_id TEXT,  -- 发电编号
  document_id TEXT,  -- 发电文号
  date_time TEXT,  -- 发电时间
  department_name TEXT,  -- 发电单位
  title TEXT,  -- 文件标题
  urgency_level TEXT,  -- 等级
  secret_level TEXT,  -- 密级
  page_number TEXT,  -- 页数
  operator TEXT,  -- 值机员工号
  send_to_list TEXT,  -- 主送，竖线分割的部门名称串
  copy_to_list TEXT,  -- 抄送，竖线分割的部门名称串
  copy_report_list TEXT  -- 抄报，竖线分割的抄报对象串
);

-- 部门信息表
-- DROP TABLE pta_DepartmentInfo;
CREATE TABLE pta_DepartmentInfo
(
  id INTEGER PRIMARY KEY,  -- 部门编号
  name TEXT,  -- 部门名称
  parent_id TEXT,  -- 上一级部门编号
  department_id TEXT,  -- 实际部门编号
  ip TEXT, -- 部门的IP地址
  port TEXT -- 部门的端口号
); 

-- 操作员信息表
-- DROP TABLE pta_OperatorInfo;
CREATE TABLE pta_OperatorInfo
(
  id INTEGER,
  operator_id TEXT,  -- 工号
  name TEXT,  -- 姓名
  department INTEGER,  -- 所属部门
  FOREIGN KEY(department) REFERENCES pta_DepartmentInfo(id)
);

-- 配置信息表
-- DROP TABLE pta_ConfigInfo;
CREATE TABLE pta_ConfigInfo
(
  my_department_name TEXT,  -- 自己的部门名称
  my_max_telegram_id TEXT,  -- 当前已使用的最大发电编号，如“2013112601”
  my_max_document_id TEXT,  -- 当前已使用的最大发电文号，如“X公密发[2013]1号”
  my_ip TEXT,  -- 自己的IP地址
  my_port TEXT  -- 自己的端口号
);