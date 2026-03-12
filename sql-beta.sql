-- -- 创建媒体库数据库
-- CREATE DATABASE media_library;

-- -- 使用媒体库数据库
-- USE media_library;

-- -- 媒体文件元数据表
-- CREATE TABLE media_files (
--     id INT,
--     file_name STRING,
--     file_path STRING,
--     file_size BIGINT,
--     file_type STRING,
--     mime_type STRING,
--     width INT,
--     height INT,
--     duration INT,
--     create_time STRING,
--     modify_time STRING,
--     tags STRING,
--     thumbnail_path STRING
-- );

-- -- 相册/播放列表表
-- CREATE TABLE albums (
--     id INT,
--     name STRING,
--     description STRING,
--     create_time STRING
-- );

-- -- 关联表
-- CREATE TABLE album_media (
--     album_id INT,
--     media_id INT,
--     add_time STRING
-- );

-- -- 插入示例媒体文件数据
-- INSERT INTO media_files (id, file_name, file_path, file_size, file_type, mime_type, width, height, duration, create_time, modify_time, tags, thumbnail_path) VALUES (1, 'vacation.jpg', '/photos/vacation.jpg', 2048000, 'image', 'image/jpeg', 1920, 1080, 0, '2026-01-15', '2026-01-15', 'vacation,beach,summer', '/thumbs/vacation_thumb.jpg');
-- INSERT INTO media_files (id, file_name, file_path, file_size, file_type, mime_type, width, height, duration, create_time, modify_time, tags, thumbnail_path) VALUES (2, 'birthday.mp4', '/videos/birthday.mp4', 52428800, 'video', 'video/mp4', 1920, 1080, 120, '2026-02-20', '2026-02-20', 'birthday,party,family', '/thumbs/birthday_thumb.jpg');
-- INSERT INTO media_files (id, file_name, file_path, file_size, file_type, mime_type, width, height, duration, create_time, modify_time, tags, thumbnail_path) VALUES (3, 'song.mp3', '/music/song.mp3', 5120000, 'audio', 'audio/mpeg', 0, 0, 180, '2026-03-01', '2026-03-01', 'music,favorite,relax', '');

-- -- 插入示例相册数据
-- INSERT INTO albums (id, name, description, create_time) VALUES (1, 'Summer Vacation', 'Photos from summer vacation 2026', '2026-01-20');
-- INSERT INTO albums (id, name, description, create_time) VALUES (2, 'Family Events', 'Birthday and holiday celebrations', '2026-02-25');
-- INSERT INTO albums (id, name, description, create_time) VALUES (3, 'My Music', 'Favorite songs collection', '2026-03-05');

-- -- 插入关联数据
-- INSERT INTO album_media (album_id, media_id, add_time) VALUES (1, 1, '2026-01-20');
-- INSERT INTO album_media (album_id, media_id, add_time) VALUES (2, 2, '2026-02-25');
-- INSERT INTO album_media (album_id, media_id, add_time) VALUES (3, 3, '2026-03-05');

-- -- 显示所有表
-- SHOW TABLES;

-- -- 绝对语句显示用户角色表中的所有用户ID
-- SELECT id FROM users.user_roles;

-- 联合用户表的所有数据为一张表数据: user_all
LINK TABLE FROM users.user_roles to users.permissions new user_0;
LINK TABLE FROM users.user_0 to users.notifications new user_1;
LINK TABLE FROM users.user_1 to users.login_logs new user_2;
LINK TABLE FROM users.user_2 to users.user_profile new user_3;
LINK TABLE FROM users.user_3 to users.user_account new user_all;
SELECT * FROM users.user_all;
