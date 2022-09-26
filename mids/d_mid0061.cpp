/*!
 * \file d_mid0061.cpp
 * \brief file for the definition of the class "DMid0061"
 * \author poles
 * \date 2022-09-23
 *
 * \details
 *
 * \copyright
 ****************************************************************************
 *        Ce logiciel est la propriete de DOGA®.
 *         -------------------------------------
 *
 *    Il ne peut etre reproduit ni communique en totalite ou partie sans
 *    son autorisation ecrite.
 *
 ****************************************************************************
 *        This software is the property of DOGA®.
 *         -------------------------------------
 *
 *    It cannot be reproduced nor disclosed entirely or partially without
 *    a written agreement.
 *
 ****************************************************************************
 */

#include "mids/d_mid0061.h"

#define REGISTER_RESPONSES() valid_responses.append({MID0062})

void DMid0061::processData(QByteArray data_byte_array)
{
    if (header->revision <= 1) {
        data_fields.insert(1, data_byte_array.mid(2, 4)); // Cell ID
        data_fields.insert(2, data_byte_array.mid(8, 2)); // Channel ID
        data_fields.insert(3, data_byte_array.mid(12, 25)); // Torque controller name
        data_fields.insert(4, data_byte_array.mid(39, 25)); // VIN  Number
        data_fields.insert(5, data_byte_array.mid(66, 2)); // Job ID
        data_fields.insert(6, data_byte_array.mid(70, 3)); // Parameter set ID
        data_fields.insert(7, data_byte_array.mid(75, 4)); // Batch size
        data_fields.insert(8, data_byte_array.mid(81, 4)); // Batch counter
        data_fields.insert(9, data_byte_array.mid(87, 1)); // Tightening status
        data_fields.insert(10, data_byte_array.mid(90, 1)); // Torque status
        data_fields.insert(11, data_byte_array.mid(93, 1)); // Angle status
        data_fields.insert(12, data_byte_array.mid(96, 6)); // Torque min limit
        data_fields.insert(13, data_byte_array.mid(104, 6)); // Torque max limit
        data_fields.insert(14, data_byte_array.mid(112, 6)); // Torque final target
        data_fields.insert(15, data_byte_array.mid(120, 6)); // Torque
        data_fields.insert(16, data_byte_array.mid(128, 5)); // Angle min
        data_fields.insert(17, data_byte_array.mid(135, 5)); // Angle max
        data_fields.insert(18, data_byte_array.mid(142, 5)); // Final angle target
        data_fields.insert(19, data_byte_array.mid(149, 5)); // Angle
        data_fields.insert(20, data_byte_array.mid(156, 19)); // Time stamp
        data_fields.insert(21, data_byte_array.mid(177, 19)); // Date/time of last change in parameter set settings
        data_fields.insert(22, data_byte_array.mid(198, 1)); // Batch status
        data_fields.insert(23, data_byte_array.mid(201, 10)); // Tightening ID
        return;
    }

    if (header->revision == 999) {
        data_fields.insert(-14, data_byte_array.mid(0, 25)); // VIN Number
        data_fields.insert(-13, data_byte_array.mid(25, 2)); // Job ID
        data_fields.insert(-12, data_byte_array.mid(27, 3)); // Parameter set ID
        data_fields.insert(-11, data_byte_array.mid(30, 4)); // Batch size
        data_fields.insert(-10, data_byte_array.mid(34, 4)); // Batch counter
        data_fields.insert(-9, data_byte_array.mid(38, 1)); // Batch status
        data_fields.insert(-8, data_byte_array.mid(39, 1)); // Tightening status
        data_fields.insert(-7, data_byte_array.mid(40, 1)); // Torque status
        data_fields.insert(-6, data_byte_array.mid(41, 1)); // Angles status
        data_fields.insert(-5, data_byte_array.mid(42, 6)); // Torque
        data_fields.insert(-4, data_byte_array.mid(48, 5)); // Angle
        data_fields.insert(-3, data_byte_array.mid(53, 19)); // Time Stamp
        data_fields.insert(-2, data_byte_array.mid(72, 19)); // Date/time of last change in parameter set settings
        data_fields.insert(-1, data_byte_array.mid(91, 10)); // Tightening ID
        return;
    }

    if (header->revision > 6 && header->revision < 998) // unknown revision
        return;

    // Revision 2
    data_fields.insert(1, data_byte_array.mid(2, 4)); // Cell ID
    data_fields.insert(2, data_byte_array.mid(8, 2)); // Channel ID
    data_fields.insert(3, data_byte_array.mid(12, 25)); // Torque controller name
    data_fields.insert(4, data_byte_array.mid(39, 25)); // VIN  Number
    data_fields.insert(5, data_byte_array.mid(66, 4)); // Job ID
    data_fields.insert(6, data_byte_array.mid(72, 3)); // Parameter set ID
    data_fields.insert(7, data_byte_array.mid(77, 2)); // Strategy
    data_fields.insert(8, data_byte_array.mid(81, 5)); // Strategy Options
    data_fields.insert(9, data_byte_array.mid(88, 4)); // Batch size
    data_fields.insert(10, data_byte_array.mid(94, 4)); // Batch counter
    data_fields.insert(11, data_byte_array.mid(100, 1)); // Tightening status
    data_fields.insert(12, data_byte_array.mid(103, 1)); // Batch status
    data_fields.insert(13, data_byte_array.mid(106, 1)); // Torque status
    data_fields.insert(14, data_byte_array.mid(109, 1)); // Angle status
    data_fields.insert(15, data_byte_array.mid(112, 1)); // Rundown angle status
    data_fields.insert(16, data_byte_array.mid(115, 1)); // Current monitoring status
    data_fields.insert(17, data_byte_array.mid(118, 1)); // Selftap status
    data_fields.insert(18, data_byte_array.mid(121, 1)); // Prevail torque monitoring status
    data_fields.insert(19, data_byte_array.mid(124, 1)); // Prevail torque compensate status
    data_fields.insert(20, data_byte_array.mid(127, 10)); // Tightening error status
    data_fields.insert(21, data_byte_array.mid(139, 6)); // Torque min limit
    data_fields.insert(22, data_byte_array.mid(147, 6)); // Torque max limit
    data_fields.insert(23, data_byte_array.mid(155, 6)); // Torque final target
    data_fields.insert(24, data_byte_array.mid(163, 6)); // Torque
    data_fields.insert(25, data_byte_array.mid(171, 5)); // Angle min
    data_fields.insert(26, data_byte_array.mid(178, 5)); // Angle max
    data_fields.insert(27, data_byte_array.mid(185, 5)); // Final angle target
    data_fields.insert(28, data_byte_array.mid(192, 5)); // Angle
    data_fields.insert(29, data_byte_array.mid(199, 5)); // Rundown angle min
    data_fields.insert(30, data_byte_array.mid(206, 5)); // Rundown angle max
    data_fields.insert(31, data_byte_array.mid(213, 5)); // Rundown angle
    data_fields.insert(32, data_byte_array.mid(220, 3)); // Current monitoring min
    data_fields.insert(33, data_byte_array.mid(225, 3)); // Current monitoring max
    data_fields.insert(34, data_byte_array.mid(230, 3)); // Current monitoring value
    data_fields.insert(35, data_byte_array.mid(235, 6)); // Selftap min
    data_fields.insert(36, data_byte_array.mid(243, 6)); // Selftap max
    data_fields.insert(37, data_byte_array.mid(251, 6)); // Selftap torque
    data_fields.insert(38, data_byte_array.mid(259, 6)); // Prevail torque monitoring min
    data_fields.insert(39, data_byte_array.mid(267, 6)); // Prevail torque monitoring max
    data_fields.insert(40, data_byte_array.mid(275, 6)); // Prevail torque
    data_fields.insert(41, data_byte_array.mid(283, 10)); // Tightening ID
    data_fields.insert(42, data_byte_array.mid(295, 5)); // Job sequence number
    data_fields.insert(43, data_byte_array.mid(302, 5)); // Sync tightening ID
    data_fields.insert(44, data_byte_array.mid(309, 14)); // Tool serial number
    data_fields.insert(45, data_byte_array.mid(325, 19)); // Time stamp
    data_fields.insert(46, data_byte_array.mid(346, 19)); // Date/time of last change in parameter set settings



    if (header->revision < 3)
        return;
    data_fields.insert(47, data_byte_array.mid(367, 25)); // Parameter set name
    data_fields.insert(48, data_byte_array.mid(394, 1)); // Torques values unit
    data_fields.insert(49, data_byte_array.mid(397, 2)); // Result type


    if (header->revision < 4)
        return;
    data_fields.insert(50, data_byte_array.mid(401, 25)); // Id result part 2
    data_fields.insert(51, data_byte_array.mid(428, 25)); // Id Result part 3
    data_fields.insert(52, data_byte_array.mid(455, 25)); // Id result part 4

    if (header->revision < 5) // On going TODO review
        return;
    data_fields.insert(53, data_byte_array.mid(482, 4)); // Customer tightening error code

    if (header->revision < 6)
        return;
    data_fields.insert(54, data_byte_array.mid(488, 6)); // Prevail torque cempensate value
    data_fields.insert(55, data_byte_array.mid(496, 10)); // Tightening error status 2

    if (header->revision == 7)
    {
        data_fields.insert(56, data_byte_array.mid(508, 7)); // Compensated angle
        data_fields.insert(57, data_byte_array.mid(517, 7)); // Final angle decimal
    }

    if (header->revision == 998)
    {
        data_fields.insert(56, data_byte_array.mid(508, 2)); // Number of stages in multistage
        data_fields.insert(57, data_byte_array.mid(512, 2)); // Number of stage results
        int stage_result = data_fields[57].toInt();
        data_fields.insert(68, data_byte_array.mid(516, 11 * stage_result)); // Stage result
    }
}

DMid0061::DMid0061(QByteArray arr)
    : DOpenProtocolMid(arr)
{
    DMid0061::processData(arr.mid(20, -1));
    REGISTER_RESPONSES();
}

DMid0061::DMid0061(QMap<int, QByteArray> args, int spindle_id) : DMid0061(-1, args, spindle_id)
{}

DMid0061::DMid0061(int revision, QMap<int, QByteArray> args, int spindle_id)
    : DMid0061(revision, args, spindle_id, 1)
{}

DMid0061::DMid0061(int revision, QMap<int, QByteArray> args, int spindle_id, int station_id)
{
    data_fields = args;
    QString header_str = formatNumber(getDataFieldsLength() + 20, 4);
    header_str += "0061";
    header_str += revision < 0 ? "   " : formatNumber(revision, 3);
    header_str += '0'; // No ack flag
    header_str += formatNumber(station_id, 1); // Station ID
    header_str += formatNumber(spindle_id, 2); // spindle_id
    header_str += "     "; // 5 space reserved

    header = std::make_shared<DOpenProtocolHeader>(header_str);
    REGISTER_RESPONSES();

    // Assign MID enum from its ID
    mid_ID = static_cast<midType>(header->mid);
}

