#pragma once

// ABLETON
#include "src/ableton/abletonobject.h"


M_FORWARD_ABLETON(AlsName)
M_FORWARD_ABLETON(AlsDeviceChain)
M_FORWARD_ABLETON(AlsTrackDelay)


M_NAMESPACE_ABLETON_BEGIN


class AlsTrack : public AbletonObject
{
public:
  AlsTrack();
  ~AlsTrack();


  void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);

  /// <summary>
  /// Sets the lom identifier.
  /// </summary>
  /// <param name="value">The value.</param>
  void setLomId(const QString &r_value_);


  /// <summary>
  /// Sets the lom identifier view.
  /// </summary>
  /// <param name="value">The value.</param>
  void setLomIdView(const QString &r_value_);


  /// <summary>
  /// Sets the envelope mode preferred.
  /// </summary>
  /// <param name="value">The value.</param>
  void setEnvelopeModePreferred(const QString &r_value_);


  /// <summary>
  /// Sets the index of the color.
  /// </summary>
  /// <param name="value">The value.</param>
  void setColorIndex(const QString &r_value_);


  /// <summary>
  /// Sets the track group identifier.
  /// </summary>
  /// <param name="value">The value.</param>
  void setTrackGroupId(const QString &r_value_);


  /// <summary>
  /// Creates the name.
  /// </summary>
  /// <returns></returns>
  QSharedPointer<QObject> createName();


  /// <summary>
  /// Creates the track delay.
  /// </summary>
  /// <returns></returns>
  QSharedPointer<QObject> createTrackDelay();


  /// <summary>
  /// Creates the device chain.
  /// </summary>
  /// <returns></returns>
  QSharedPointer<QObject> createDeviceChain();
#pragma endregion

    int LomId;
    int LomIdView;
    bool EnvelopeModePreferred;
    QSharedPointer<AlsName> Name;
    QSharedPointer<AlsTrackDelay> TrackDelay;
    int ColorIndex;
    int TrackGroupId;
    QSharedPointer<AlsDeviceChain> DeviceChain;

};


M_NAMESPACE_ABLETON_END
