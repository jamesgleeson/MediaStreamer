CREATE DATABASE  IF NOT EXISTS `MediaStreamer` /*!40100 DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci */;
USE `MediaStreamer`;
-- MySQL dump 10.13  Distrib 5.5.16, for Win32 (x86)
--
-- Host: localhost    Database: MediaStreamer
-- ------------------------------------------------------
-- Server version	5.1.57-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `SpeakerBroadcastItems`
--

DROP TABLE IF EXISTS `SpeakerBroadcastItems`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `SpeakerBroadcastItems` (
  `SB_ITEM_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `USR_ID` int(10) unsigned NOT NULL,
  `CONT_ID` int(10) unsigned NOT NULL,
  PRIMARY KEY (`SB_ITEM_ID`),
  KEY `CONT_ID` (`CONT_ID`),
  KEY `USR_ID` (`USR_ID`),
  CONSTRAINT `FK_CONT_ID3` FOREIGN KEY (`CONT_ID`) REFERENCES `Contents` (`CONT_ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `FK_USR_ID2` FOREIGN KEY (`USR_ID`) REFERENCES `Users` (`USR_ID`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `SpeakerBroadcastItems`
--

LOCK TABLES `SpeakerBroadcastItems` WRITE;
/*!40000 ALTER TABLE `SpeakerBroadcastItems` DISABLE KEYS */;
/*!40000 ALTER TABLE `SpeakerBroadcastItems` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ScreenAreaExtraordinaryBroadcastItems`
--

DROP TABLE IF EXISTS `ScreenAreaExtraordinaryBroadcastItems`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ScreenAreaExtraordinaryBroadcastItems` (
  `SCRN_AREA_ID` int(10) unsigned NOT NULL,
  `EB_ITEM_ID` int(10) unsigned NOT NULL,
  PRIMARY KEY (`SCRN_AREA_ID`,`EB_ITEM_ID`),
  KEY `SCRN_AREA_ID` (`SCRN_AREA_ID`),
  KEY `EB_ITEM_ID` (`EB_ITEM_ID`),
  CONSTRAINT `FK_SCRN_AREA_ID` FOREIGN KEY (`SCRN_AREA_ID`) REFERENCES `ScreenAreas` (`SCRN_AREA_ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `FK_EB_ITEM_ID` FOREIGN KEY (`EB_ITEM_ID`) REFERENCES `ExtraordinaryBroadcastItems` (`EB_ITEM_ID`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ScreenAreaExtraordinaryBroadcastItems`
--

LOCK TABLES `ScreenAreaExtraordinaryBroadcastItems` WRITE;
/*!40000 ALTER TABLE `ScreenAreaExtraordinaryBroadcastItems` DISABLE KEYS */;
/*!40000 ALTER TABLE `ScreenAreaExtraordinaryBroadcastItems` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Cameras`
--

DROP TABLE IF EXISTS `Cameras`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Cameras` (
  `CAM_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `TERM_ID` int(10) unsigned NOT NULL,
  `CAM_NAME` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `CAM_DESC` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL,
  `CAM_IP_ADDRESS` varchar(29) COLLATE utf8_unicode_ci NOT NULL,
  `CAM_PORT` int(10) unsigned DEFAULT NULL,
  `CAM_REG_DT` datetime NOT NULL,
  PRIMARY KEY (`CAM_ID`),
  KEY `CAM_IP_ADDRESS` (`CAM_IP_ADDRESS`),
  KEY `CAM_PORT` (`CAM_PORT`),
  KEY `FK_TERM_ID` (`TERM_ID`),
  CONSTRAINT `FK_TERM_ID` FOREIGN KEY (`TERM_ID`) REFERENCES `Terminals` (`TERM_ID`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Cameras`
--

LOCK TABLES `Cameras` WRITE;
/*!40000 ALTER TABLE `Cameras` DISABLE KEYS */;
/*!40000 ALTER TABLE `Cameras` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ExtraordinaryBroadcastItems`
--

DROP TABLE IF EXISTS `ExtraordinaryBroadcastItems`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ExtraordinaryBroadcastItems` (
  `EB_ITEM_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `CONT_ID` int(10) unsigned NOT NULL,
  `EB_ITEM_NAME` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `EB_ITEM_START_DATE` date NOT NULL,
  `EB_ITEM_END_DATE` date NOT NULL,
  `EB_ITEM_START_TIME` time NOT NULL,
  `EB_ITEM_END_TIME` time NOT NULL,
  `EB_ITEM_REPEAT_RULE` varchar(10) COLLATE utf8_unicode_ci NOT NULL,
  `EB_ITEM_REPEAT_RULE_VALUE` varchar(45) COLLATE utf8_unicode_ci NOT NULL,
  `EB_ITEM_REG_DT` datetime NOT NULL,
  `EB_ITEM_DESC` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`EB_ITEM_ID`),
  KEY `CONT_ID` (`CONT_ID`),
  CONSTRAINT `FK_CONT_ID2` FOREIGN KEY (`CONT_ID`) REFERENCES `Contents` (`CONT_ID`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ExtraordinaryBroadcastItems`
--

LOCK TABLES `ExtraordinaryBroadcastItems` WRITE;
/*!40000 ALTER TABLE `ExtraordinaryBroadcastItems` DISABLE KEYS */;
/*!40000 ALTER TABLE `ExtraordinaryBroadcastItems` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Medias`
--

DROP TABLE IF EXISTS `Medias`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Medias` (
  `MD_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `MD_TYPE` int(10) unsigned NOT NULL,
  `MD_FORMAT` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `MD_NAME` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `MD_THUMB` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL,
  `MD_LOCATION` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `MD_DURATION` int(10) unsigned NOT NULL,
  `MD_REG_DT` datetime NOT NULL,
  `MD_DESC` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`MD_ID`),
  KEY `MD_FORMAT` (`MD_FORMAT`),
  KEY `MD_NAME` (`MD_NAME`),
  KEY `MD_TYPE` (`MD_TYPE`),
  CONSTRAINT `FK_MD_TYPE` FOREIGN KEY (`MD_TYPE`) REFERENCES `MediaTypes` (`MT_ID`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Medias`
--

LOCK TABLES `Medias` WRITE;
/*!40000 ALTER TABLE `Medias` DISABLE KEYS */;
/*!40000 ALTER TABLE `Medias` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Streams`
--

DROP TABLE IF EXISTS `Streams`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Streams` (
  `ST_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `ST_IP_ADDRESS` varchar(29) COLLATE utf8_unicode_ci NOT NULL,
  `ST_PORT` smallint(5) unsigned NOT NULL,
  `ST_TYPE` varchar(10) COLLATE utf8_unicode_ci NOT NULL,
  `ST_START_DT` datetime NOT NULL,
  `ST_END_DT` datetime NOT NULL,
  PRIMARY KEY (`ST_ID`),
  KEY `ST_TYPE` (`ST_TYPE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Streams`
--

LOCK TABLES `Streams` WRITE;
/*!40000 ALTER TABLE `Streams` DISABLE KEYS */;
/*!40000 ALTER TABLE `Streams` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `TerminalLogs`
--

DROP TABLE IF EXISTS `TerminalLogs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `TerminalLogs` (
  `LOG_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `TERM_ID` int(10) unsigned NOT NULL,
  `LOG_NAME` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `LOG_DT` datetime NOT NULL,
  PRIMARY KEY (`LOG_ID`),
  KEY `TERM_ID` (`TERM_ID`),
  CONSTRAINT `FK_TERM_ID2` FOREIGN KEY (`TERM_ID`) REFERENCES `Terminals` (`TERM_GR_ID`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `TerminalLogs`
--

LOCK TABLES `TerminalLogs` WRITE;
/*!40000 ALTER TABLE `TerminalLogs` DISABLE KEYS */;
/*!40000 ALTER TABLE `TerminalLogs` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ErrorLogs`
--

DROP TABLE IF EXISTS `ErrorLogs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ErrorLogs` (
  `LOG_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `LOG_NAME` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `LOG_DT` datetime NOT NULL,
  `LOG_DESC` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`LOG_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ErrorLogs`
--

LOCK TABLES `ErrorLogs` WRITE;
/*!40000 ALTER TABLE `ErrorLogs` DISABLE KEYS */;
/*!40000 ALTER TABLE `ErrorLogs` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ActionLogs`
--

DROP TABLE IF EXISTS `ActionLogs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ActionLogs` (
  `LOG_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `USR_ID` int(10) unsigned NOT NULL,
  `ACT_TYPE` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `ACT_PREDMET` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `ACT_DESC` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `ACT_DT` datetime NOT NULL,
  PRIMARY KEY (`LOG_ID`),
  KEY `ACT_TYPE` (`ACT_TYPE`),
  KEY `ACT_PREDMET` (`ACT_PREDMET`),
  KEY `ACT_DT` (`ACT_DT`),
  KEY `USR_ID` (`USR_ID`),
  CONSTRAINT `USR_ID` FOREIGN KEY (`USR_ID`) REFERENCES `Users` (`USR_ID`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ActionLogs`
--

LOCK TABLES `ActionLogs` WRITE;
/*!40000 ALTER TABLE `ActionLogs` DISABLE KEYS */;
/*!40000 ALTER TABLE `ActionLogs` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `MediaGroups`
--

DROP TABLE IF EXISTS `MediaGroups`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `MediaGroups` (
  `MG_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `MG_NAME` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `MG_TYPE` int(10) unsigned NOT NULL,
  `MG_REG_DT` datetime NOT NULL,
  `MG_DESC` varchar(45) COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`MG_ID`),
  KEY `MG_TYPE` (`MG_TYPE`),
  CONSTRAINT `FK_MG_TYPE` FOREIGN KEY (`MG_TYPE`) REFERENCES `MediaTypes` (`MT_ID`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `MediaGroups`
--

LOCK TABLES `MediaGroups` WRITE;
/*!40000 ALTER TABLE `MediaGroups` DISABLE KEYS */;
/*!40000 ALTER TABLE `MediaGroups` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `MediaGroupItems`
--

DROP TABLE IF EXISTS `MediaGroupItems`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `MediaGroupItems` (
  `MG_ID` int(10) unsigned NOT NULL,
  `MD_ID` int(10) unsigned NOT NULL,
  PRIMARY KEY (`MG_ID`,`MD_ID`),
  KEY `FK_MG_ID` (`MG_ID`),
  KEY `FK_MD_ID` (`MD_ID`),
  CONSTRAINT `FK_MG_ID` FOREIGN KEY (`MG_ID`) REFERENCES `MediaGroups` (`MG_ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `FK_MD_ID` FOREIGN KEY (`MD_ID`) REFERENCES `Medias` (`MD_ID`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `MediaGroupItems`
--

LOCK TABLES `MediaGroupItems` WRITE;
/*!40000 ALTER TABLE `MediaGroupItems` DISABLE KEYS */;
/*!40000 ALTER TABLE `MediaGroupItems` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `MediaTexts`
--

DROP TABLE IF EXISTS `MediaTexts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `MediaTexts` (
  `MT_ID` int(11) NOT NULL,
  `MD_ID` int(10) unsigned NOT NULL,
  `MT_TEXT` text COLLATE utf8_unicode_ci NOT NULL,
  `MT_DIRECTION` varchar(3) COLLATE utf8_unicode_ci NOT NULL,
  `MT_SPEED` tinyint(1) NOT NULL,
  `MT_POS_X` smallint(6) NOT NULL DEFAULT '0',
  `MT_POS_Y` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`MT_ID`),
  KEY `MD_ID` (`MD_ID`),
  CONSTRAINT `FK_MD_ID1` FOREIGN KEY (`MD_ID`) REFERENCES `Medias` (`MD_ID`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `MediaTexts`
--

LOCK TABLES `MediaTexts` WRITE;
/*!40000 ALTER TABLE `MediaTexts` DISABLE KEYS */;
/*!40000 ALTER TABLE `MediaTexts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ScreenAreas`
--

DROP TABLE IF EXISTS `ScreenAreas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ScreenAreas` (
  `SCRN_AREA_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `SCRN_AREA_NAME` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `SCRN_AREA_POS_X` smallint(6) NOT NULL DEFAULT '0',
  `SCRN_AREA_POS_Y` smallint(6) NOT NULL DEFAULT '0',
  `SCRN_AREA_WIDTH` smallint(6) NOT NULL DEFAULT '800',
  `SCRN_AREA_HEIGHT` smallint(6) NOT NULL DEFAULT '600',
  `SCRN_AREA_REG_DT` datetime NOT NULL,
  `SCRN_AREA_IS_MAIN` tinyint(2) NOT NULL DEFAULT '0',
  `SCRN_AREA_DESC` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`SCRN_AREA_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ScreenAreas`
--

LOCK TABLES `ScreenAreas` WRITE;
/*!40000 ALTER TABLE `ScreenAreas` DISABLE KEYS */;
/*!40000 ALTER TABLE `ScreenAreas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ScheduleItems`
--

DROP TABLE IF EXISTS `ScheduleItems`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ScheduleItems` (
  `SCH_ITEM_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `SCH_ID` int(10) unsigned NOT NULL,
  `SCH_ITEM_NAME` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `SCH_ITEM_START_DATE` date DEFAULT NULL,
  `SCH_ITEM_END_DATE` date DEFAULT NULL,
  `SCH_ITEM_START_TIME` time DEFAULT NULL,
  `SCH_ITEM_END_TIME` time DEFAULT NULL,
  `SCH_ITEM_FILL_RULE` varchar(10) COLLATE utf8_unicode_ci DEFAULT NULL,
  `SCH_ITEM_REPEAT_RULE` varchar(10) COLLATE utf8_unicode_ci DEFAULT NULL,
  `SCH_ITEM_REPEAT_RULE_VALUE` varchar(45) COLLATE utf8_unicode_ci DEFAULT NULL,
  `CONT_ID` int(10) unsigned NOT NULL,
  `SCH_ITEM_REG_DT` datetime NOT NULL,
  `SCH_ITEM_DESC` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`SCH_ITEM_ID`),
  KEY `FK_CONT_ID` (`CONT_ID`),
  KEY `FK_SCH_ID_idx` (`SCH_ID`),
  CONSTRAINT `FK_SCH_ID` FOREIGN KEY (`SCH_ID`) REFERENCES `Schedules` (`SCH_ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `FK_CONT_ID` FOREIGN KEY (`CONT_ID`) REFERENCES `Contents` (`CONT_ID`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ScheduleItems`
--

LOCK TABLES `ScheduleItems` WRITE;
/*!40000 ALTER TABLE `ScheduleItems` DISABLE KEYS */;
/*!40000 ALTER TABLE `ScheduleItems` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Users`
--

DROP TABLE IF EXISTS `Users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Users` (
  `USR_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `USR_NAME` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `USR_PWD` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `USR_LAST_LOGIN_DT` datetime DEFAULT NULL,
  `USR_LAST_LOGOUT_DT` datetime DEFAULT NULL,
  `USR_REG_DT` datetime NOT NULL,
  `USR_DESC` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`USR_ID`),
  KEY `USR_NAME` (`USR_NAME`),
  KEY `USR_PWD` (`USR_PWD`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Users`
--

LOCK TABLES `Users` WRITE;
/*!40000 ALTER TABLE `Users` DISABLE KEYS */;
/*!40000 ALTER TABLE `Users` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `UserPermissions`
--

DROP TABLE IF EXISTS `UserPermissions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `UserPermissions` (
  `USR_PRM_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `USR_PRM_VALUE` tinyint(2) unsigned NOT NULL,
  `USR_ID` int(11) unsigned NOT NULL,
  `PRM_ID` int(11) unsigned NOT NULL,
  PRIMARY KEY (`USR_PRM_ID`),
  KEY `PRM_ID` (`PRM_ID`),
  KEY `USR_ID` (`USR_ID`),
  CONSTRAINT `FK_PRM_ID` FOREIGN KEY (`PRM_ID`) REFERENCES `Permissions` (`PRM_ID`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `FK_USR_ID` FOREIGN KEY (`USR_ID`) REFERENCES `Users` (`USR_ID`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `UserPermissions`
--

LOCK TABLES `UserPermissions` WRITE;
/*!40000 ALTER TABLE `UserPermissions` DISABLE KEYS */;
/*!40000 ALTER TABLE `UserPermissions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `TerminalCameras`
--

DROP TABLE IF EXISTS `TerminalCameras`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `TerminalCameras` (
  `TERM_ID` int(10) unsigned NOT NULL,
  `CAM_ID` int(10) unsigned NOT NULL,
  PRIMARY KEY (`TERM_ID`,`CAM_ID`),
  KEY `TERM_ID` (`TERM_ID`),
  KEY `CAM_ID` (`CAM_ID`),
  CONSTRAINT `FK_TERM_ID3` FOREIGN KEY (`TERM_ID`) REFERENCES `Terminals` (`TERM_ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `FK_CAM_ID` FOREIGN KEY (`CAM_ID`) REFERENCES `Cameras` (`CAM_ID`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `TerminalCameras`
--

LOCK TABLES `TerminalCameras` WRITE;
/*!40000 ALTER TABLE `TerminalCameras` DISABLE KEYS */;
/*!40000 ALTER TABLE `TerminalCameras` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ScreenAreaSchedules`
--

DROP TABLE IF EXISTS `ScreenAreaSchedules`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ScreenAreaSchedules` (
  `SCRN_AREA_ID` int(10) unsigned NOT NULL,
  `SCH_ID` int(10) unsigned NOT NULL,
  PRIMARY KEY (`SCRN_AREA_ID`,`SCH_ID`),
  KEY `SCH_ID` (`SCH_ID`),
  KEY `SCRN_AREA_ID` (`SCRN_AREA_ID`),
  CONSTRAINT `SCH_ID` FOREIGN KEY (`SCH_ID`) REFERENCES `Schedules` (`SCH_ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `SCRN_AREA_ID` FOREIGN KEY (`SCRN_AREA_ID`) REFERENCES `ScreenAreas` (`SCRN_AREA_ID`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ScreenAreaSchedules`
--

LOCK TABLES `ScreenAreaSchedules` WRITE;
/*!40000 ALTER TABLE `ScreenAreaSchedules` DISABLE KEYS */;
/*!40000 ALTER TABLE `ScreenAreaSchedules` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ServerLogs`
--

DROP TABLE IF EXISTS `ServerLogs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ServerLogs` (
  `LOG_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `SRV_ID` int(10) unsigned NOT NULL,
  `LOG_NAME` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `LOG_DESC` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`LOG_ID`),
  KEY `SRV_ID` (`SRV_ID`),
  CONSTRAINT `FK_SRV_ID2` FOREIGN KEY (`SRV_ID`) REFERENCES `Servers` (`SRV_ID`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ServerLogs`
--

LOCK TABLES `ServerLogs` WRITE;
/*!40000 ALTER TABLE `ServerLogs` DISABLE KEYS */;
/*!40000 ALTER TABLE `ServerLogs` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Servers`
--

DROP TABLE IF EXISTS `Servers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Servers` (
  `SRV_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `SRV_NAME` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `SRV_IP_ADDRESS` varchar(29) COLLATE utf8_unicode_ci NOT NULL,
  `SRV_PORT` int(10) unsigned NOT NULL,
  `SRV_DESC` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`SRV_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Servers`
--

LOCK TABLES `Servers` WRITE;
/*!40000 ALTER TABLE `Servers` DISABLE KEYS */;
/*!40000 ALTER TABLE `Servers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Screens`
--

DROP TABLE IF EXISTS `Screens`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Screens` (
  `SCRN_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `TERM_ID` int(10) unsigned NOT NULL,
  `SCRN_NAME` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `SCRN_REG_DT` datetime NOT NULL,
  `SCRN_DESC` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL,
  `SCRN_WIDTH` smallint(5) unsigned NOT NULL,
  `SCRN_HEIGHT` smallint(5) unsigned NOT NULL,
  PRIMARY KEY (`SCRN_ID`),
  KEY `TERM_ID` (`TERM_ID`),
  KEY `FK_TERM_ID4_idx` (`TERM_ID`),
  CONSTRAINT `FK_TERM_ID4` FOREIGN KEY (`TERM_ID`) REFERENCES `Terminals` (`TERM_ID`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Screens`
--

LOCK TABLES `Screens` WRITE;
/*!40000 ALTER TABLE `Screens` DISABLE KEYS */;
/*!40000 ALTER TABLE `Screens` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Terminals`
--

DROP TABLE IF EXISTS `Terminals`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Terminals` (
  `TERM_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `TERM_GR_ID` int(10) unsigned NOT NULL,
  `TERM_NAME` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `TERM_IP_ADDRESS` varchar(29) COLLATE utf8_unicode_ci NOT NULL,
  `TERM_PORT` int(10) unsigned NOT NULL,
  `TERM_REG_DT` datetime NOT NULL,
  `TERM_DESC` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL,
  `SRV_ID` int(11) unsigned NOT NULL,
  PRIMARY KEY (`TERM_ID`),
  KEY `TERM_GR_ID` (`TERM_GR_ID`),
  KEY `TERM_IP_ADDRESS` (`TERM_IP_ADDRESS`),
  KEY `TERM_PORT` (`TERM_PORT`),
  KEY `FK_SRV_ID_idx` (`SRV_ID`),
  CONSTRAINT `FK_SRV_ID` FOREIGN KEY (`SRV_ID`) REFERENCES `Servers` (`SRV_ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `FK_TERM_GR_ID` FOREIGN KEY (`TERM_GR_ID`) REFERENCES `TerminalGroups` (`TERM_GR_ID`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Terminals`
--

LOCK TABLES `Terminals` WRITE;
/*!40000 ALTER TABLE `Terminals` DISABLE KEYS */;
/*!40000 ALTER TABLE `Terminals` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `MediaTypes`
--

DROP TABLE IF EXISTS `MediaTypes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `MediaTypes` (
  `MT_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `MT_NAME` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `MT_DESC` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`MT_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `MediaTypes`
--

LOCK TABLES `MediaTypes` WRITE;
/*!40000 ALTER TABLE `MediaTypes` DISABLE KEYS */;
/*!40000 ALTER TABLE `MediaTypes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `TerminalGroups`
--

DROP TABLE IF EXISTS `TerminalGroups`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `TerminalGroups` (
  `TERM_GR_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `TERM_GR_NAME` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `TERM_GR_DESC` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL,
  `TERM_GR_PARENT_ID` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`TERM_GR_ID`),
  KEY `TERM_GR_PARENT_ID` (`TERM_GR_PARENT_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `TerminalGroups`
--

LOCK TABLES `TerminalGroups` WRITE;
/*!40000 ALTER TABLE `TerminalGroups` DISABLE KEYS */;
/*!40000 ALTER TABLE `TerminalGroups` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Schedules`
--

DROP TABLE IF EXISTS `Schedules`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Schedules` (
  `SCH_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `SCH_NAME` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL,
  `SCH_LOCATION` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL,
  `SCH_IS_ACTIVE` tinyint(2) DEFAULT NULL,
  `SCH_REG_DT` datetime DEFAULT NULL,
  `SCH_DESC` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`SCH_ID`),
  KEY `SCH_IS_ACT` (`SCH_IS_ACTIVE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Schedules`
--

LOCK TABLES `Schedules` WRITE;
/*!40000 ALTER TABLE `Schedules` DISABLE KEYS */;
/*!40000 ALTER TABLE `Schedules` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ScreenAreaSpeakerBroadcastItems`
--

DROP TABLE IF EXISTS `ScreenAreaSpeakerBroadcastItems`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ScreenAreaSpeakerBroadcastItems` (
  `SCRN_AREA_ID` int(10) unsigned NOT NULL,
  `SB_ITEM_ID` int(10) unsigned NOT NULL,
  PRIMARY KEY (`SCRN_AREA_ID`,`SB_ITEM_ID`),
  KEY `FK_SB_ITEM_ID` (`SB_ITEM_ID`),
  KEY `FK_SCRN_AREA_ID2` (`SCRN_AREA_ID`),
  CONSTRAINT `FK_SB_ITEM_ID` FOREIGN KEY (`SB_ITEM_ID`) REFERENCES `SpeakerBroadcastItems` (`SB_ITEM_ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `FK_SCRN_AREA_ID2` FOREIGN KEY (`SCRN_AREA_ID`) REFERENCES `ScreenAreas` (`SCRN_AREA_ID`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ScreenAreaSpeakerBroadcastItems`
--

LOCK TABLES `ScreenAreaSpeakerBroadcastItems` WRITE;
/*!40000 ALTER TABLE `ScreenAreaSpeakerBroadcastItems` DISABLE KEYS */;
/*!40000 ALTER TABLE `ScreenAreaSpeakerBroadcastItems` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `TerminalScreenAreas`
--

DROP TABLE IF EXISTS `TerminalScreenAreas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `TerminalScreenAreas` (
  `SCRN_ID` int(10) unsigned NOT NULL,
  `SCRN_AREA_ID` int(10) unsigned NOT NULL,
  PRIMARY KEY (`SCRN_ID`,`SCRN_AREA_ID`),
  KEY `SCRN_ID` (`SCRN_ID`),
  KEY `SCRN_AREA_ID` (`SCRN_AREA_ID`),
  CONSTRAINT `FK_SCRN_AREA_ID1` FOREIGN KEY (`SCRN_AREA_ID`) REFERENCES `ScreenAreas` (`SCRN_AREA_ID`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `FK_SCRN_ID1` FOREIGN KEY (`SCRN_ID`) REFERENCES `Screens` (`SCRN_ID`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `TerminalScreenAreas`
--

LOCK TABLES `TerminalScreenAreas` WRITE;
/*!40000 ALTER TABLE `TerminalScreenAreas` DISABLE KEYS */;
/*!40000 ALTER TABLE `TerminalScreenAreas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Contents`
--

DROP TABLE IF EXISTS `Contents`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Contents` (
  `CONT_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `CONT_TYPE` varchar(45) COLLATE utf8_unicode_ci NOT NULL,
  `SRC_ID` int(11) NOT NULL,
  PRIMARY KEY (`CONT_ID`),
  KEY `SRC_ID` (`SRC_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Contents`
--

LOCK TABLES `Contents` WRITE;
/*!40000 ALTER TABLE `Contents` DISABLE KEYS */;
/*!40000 ALTER TABLE `Contents` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Permissions`
--

DROP TABLE IF EXISTS `Permissions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Permissions` (
  `PRM_ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `PRM_NAME` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `PRM_DESC` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`PRM_ID`),
  KEY `PRM_ID` (`PRM_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Permissions`
--

LOCK TABLES `Permissions` WRITE;
/*!40000 ALTER TABLE `Permissions` DISABLE KEYS */;
/*!40000 ALTER TABLE `Permissions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping events for database 'MediaStreamer'
--

--
-- Dumping routines for database 'MediaStreamer'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2012-08-07 23:08:07
