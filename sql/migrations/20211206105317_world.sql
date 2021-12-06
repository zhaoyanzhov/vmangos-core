DROP PROCEDURE IF EXISTS add_migration;
delimiter ??
CREATE PROCEDURE `add_migration`()
BEGIN
DECLARE v INT DEFAULT 1;
SET v = (SELECT COUNT(*) FROM `migrations` WHERE `id`='20211206105317');
IF v=0 THEN
INSERT INTO `migrations` VALUES ('20211206105317');
-- Add your query below.


-- Add waypoints for Dragonmaw Battlemaster.
UPDATE `creature` SET `position_x`=-3636.691162, `position_y`=-2575.782471, `position_z`=52.489182, `orientation`=5.591 WHERE `guid`=49203;
DELETE FROM `creature_movement` WHERE `id`=49203;
INSERT INTO `creature_movement` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `waittime`, `wander_distance`, `script_id`) VALUES
(49203, 1, -3636.691162, -2575.782471, 52.489182, 100.000000, 0, 0.000000, 0),
(49203, 2, -3633.638672, -2578.425537, 52.307682, 100.000000, 0, 0.000000, 0),
(49203, 3, -3619.209229, -2566.885986, 51.924690, 100.000000, 0, 0.000000, 0),
(49203, 4, -3613.881104, -2546.878662, 51.100456, 100.000000, 0, 0.000000, 0),
(49203, 5, -3609.082275, -2531.322510, 52.576485, 100.000000, 0, 0.000000, 0),
(49203, 6, -3601.810791, -2522.197998, 53.701099, 100.000000, 0, 0.000000, 0),
(49203, 7, -3582.106934, -2508.576172, 52.491993, 100.000000, 0, 0.000000, 0),
(49203, 8, -3570.963379, -2504.168945, 52.065716, 100.000000, 0, 0.000000, 0),
(49203, 9, -3554.966797, -2502.763916, 51.997929, 100.000000, 0, 0.000000, 0),
(49203, 10, -3528.406982, -2511.557617, 52.005314, 100.000000, 0, 0.000000, 0),
(49203, 11, -3503.364014, -2531.909180, 52.025532, 100.000000, 0, 0.000000, 0),
(49203, 12, -3481.881836, -2549.726563, 54.679131, 100.000000, 0, 0.000000, 0),
(49203, 13, -3503.615967, -2534.690918, 52.197018, 100.000000, 0, 0.000000, 0),
(49203, 14, -3522.483398, -2502.523193, 52.158173, 100.000000, 0, 0.000000, 0),
(49203, 15, -3519.480713, -2471.022217, 48.793964, 100.000000, 0, 0.000000, 0),
(49203, 16, -3502.892822, -2455.010254, 46.700302, 100.000000, 0, 0.000000, 0),
(49203, 17, -3481.472168, -2436.851563, 48.983509, 100.000000, 0, 0.000000, 0),
(49203, 18, -3468.351807, -2417.002197, 52.415760, 100.000000, 0, 0.000000, 0),
(49203, 19, -3444.650635, -2402.431641, 52.040829, 100.000000, 0, 0.000000, 0),
(49203, 20, -3434.580811, -2386.154541, 52.023613, 100.000000, 0, 0.000000, 0),
(49203, 21, -3424.215088, -2368.876709, 52.023613, 100.000000, 0, 0.000000, 0),
(49203, 22, -3402.422607, -2335.010742, 53.075493, 100.000000, 0, 0.000000, 0),
(49203, 23, -3377.108887, -2303.413086, 52.023613, 100.000000, 0, 0.000000, 0),
(49203, 24, -3367.316650, -2268.863770, 53.685970, 100.000000, 0, 0.000000, 0),
(49203, 25, -3357.786377, -2238.110596, 51.131546, 100.000000, 0, 0.000000, 0),
(49203, 26, -3357.762451, -2206.159180, 47.695904, 100.000000, 0, 0.000000, 0),
(49203, 27, -3351.109863, -2167.399414, 45.170704, 100.000000, 0, 0.000000, 0),
(49203, 28, -3356.933350, -2194.926758, 46.446583, 100.000000, 0, 0.000000, 0),
(49203, 29, -3356.370361, -2231.003174, 50.440060, 100.000000, 0, 0.000000, 0),
(49203, 30, -3360.755371, -2247.443115, 51.775215, 100.000000, 0, 0.000000, 0),
(49203, 31, -3365.363525, -2261.950928, 52.916557, 100.000000, 0, 0.000000, 0),
(49203, 32, -3373.721191, -2297.174072, 52.040771, 100.000000, 0, 0.000000, 0),
(49203, 33, -3398.007813, -2329.164063, 52.636791, 100.000000, 0, 0.000000, 0),
(49203, 34, -3420.202393, -2362.754150, 52.023613, 100.000000, 0, 0.000000, 0),
(49203, 35, -3431.528564, -2379.564697, 52.023613, 100.000000, 0, 0.000000, 0),
(49203, 36, -3437.676025, -2394.409424, 52.023609, 100.000000, 0, 0.000000, 0),
(49203, 37, -3462.991455, -2412.413330, 52.488926, 100.000000, 0, 0.000000, 0),
(49203, 38, -3476.569092, -2431.641357, 50.061176, 100.000000, 0, 0.000000, 0),
(49203, 39, -3497.297363, -2450.491211, 46.550934, 100.000000, 0, 0.000000, 0),
(49203, 40, -3516.310547, -2465.089111, 48.593361, 100.000000, 0, 0.000000, 0),
(49203, 41, -3522.935059, -2495.614258, 52.044628, 100.000000, 0, 0.000000, 0),
(49203, 42, -3506.383057, -2531.486572, 52.224335, 100.000000, 0, 0.000000, 0),
(49203, 43, -3484.176270, -2548.368896, 54.590012, 100.000000, 0, 0.000000, 0),
(49203, 44, -3497.016602, -2537.201660, 52.121780, 100.000000, 0, 0.000000, 0),
(49203, 45, -3524.797119, -2513.820557, 52.097012, 100.000000, 0, 0.000000, 0),
(49203, 46, -3546.756348, -2503.878906, 52.005314, 100.000000, 0, 0.000000, 0),
(49203, 47, -3562.658203, -2502.856934, 51.987392, 100.000000, 0, 0.000000, 0),
(49203, 48, -3574.468750, -2505.257813, 52.312412, 100.000000, 0, 0.000000, 0),
(49203, 49, -3598.484619, -2519.643311, 53.859776, 100.000000, 0, 0.000000, 0),
(49203, 50, -3604.729248, -2524.719238, 53.130264, 100.000000, 0, 0.000000, 0),
(49203, 51, -3611.500000, -2538.853516, 52.156334, 100.000000, 0, 0.000000, 0),
(49203, 52, -3617.304199, -2562.253662, 51.564999, 100.000000, 0, 0.000000, 0),
(49203, 53, -3629.947754, -2579.109131, 52.249657, 100.000000, 0, 0.000000, 0);


-- End of migration.
END IF;
END??
delimiter ; 
CALL add_migration();
DROP PROCEDURE IF EXISTS add_migration;
