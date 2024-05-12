/*
 * Strawberry Music Player
 * This file was part of Clementine.
 * Copyright 2010, David Sansome <me@davidsansome.com>
 * Copyright 2018-2024, Jonas Kvinge <jonas@jkvinge.net>
 *
 * Strawberry is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Strawberry is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Strawberry.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef COLLECTIONSETTINGSPAGE_H
#define COLLECTIONSETTINGSPAGE_H

#include "config.h"

#include <QObject>
#include <QString>
#include <QStringList>

#include "settingspage.h"

#include "core/shared_ptr.h"

class QModelIndex;
class SettingsDialog;
class CollectionBackend;
class CollectionDirectoryModel;
class CollectionSettingsDirectoryModel;
class Ui_CollectionSettingsPage;

class CollectionSettingsPage : public SettingsPage {
  Q_OBJECT

 public:
  explicit CollectionSettingsPage(SettingsDialog *dialog, QWidget *parent = nullptr);
  ~CollectionSettingsPage() override;

  static const char *kSettingsGroup;
  static const char *kSettingsCacheSize;
  static const char *kSettingsCacheSizeUnit;
  static const char *kSettingsDiskCacheEnable;
  static const char *kSettingsDiskCacheSize;
  static const char *kSettingsDiskCacheSizeUnit;
  static const int kSettingsCacheSizeDefault;
  static const int kSettingsDiskCacheSizeDefault;

  enum class CacheSizeUnit {
    KB,
    MB,
    GB,
    TB
  };

  void Load() override;
  void Save() override;

 private slots:
  void AddDirectory();
  void RemoveDirectory();

  void CurrentRowChanged(const QModelIndex &idx);
  void SongTrackingToggled();
  void DiskCacheEnable(const int state);
  void ClearPixmapDiskCache();
  void CacheSizeUnitChanged(int index);
  void DiskCacheSizeUnitChanged(int index);
  void WriteAllSongsStatisticsToFiles();

 private:
  Ui_CollectionSettingsPage *ui_;
  SharedPtr<CollectionBackend> collection_backend_;
  CollectionSettingsDirectoryModel *collectionsettings_directory_model_;
  CollectionDirectoryModel *collection_directory_model_;
  bool initialized_model_;
};

#endif  // COLLECTIONSETTINGSPAGE_H
